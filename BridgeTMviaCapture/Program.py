from tkinter import *
from tkinter import ttk
import tkinter as tk
from tkinter import filedialog
from PIL import Image as pim, ImageTk
import cv2
import numpy as np
import sqlite3
import pytesseract
import pandas.io.sql as sql
import pandas as pd
import pdfkit

def convertImage(image):
    gray = cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5),0)
    canny = cv2.Canny(blur,50,120)
    return canny

class Root(Tk):
    def __init__(self):
        super(Root, self).__init__()
        self.title("Bridge Tournament Management via Capture")
        self.area1 = tk.Label(self , text ="Bridge Tournament Management via Capture", font = ('Arial', 30))
        self.area1.pack(side=TOP,fill= BOTH ,expand = 'yes' 
        ,padx =10 , pady = 20 
        )
        self.area2 = tk.Label(self)
        self.area2.pack(side=TOP,fill= BOTH,expand = 'yes')
        self.area3 = tk.Label(self
        #,text = "3" , 
        #bg = "yellow"
        )
        self.area3.pack(side=TOP,fill= BOTH,expand = 'yes')
        
        with sqlite3.connect("bridgeTeset.sqlite") as con:
            sql_cmd = """
            CREATE TABLE IF NOT EXISTS test (
	            "Board"	INTEGER,
	            "Num"	INTEGER,
	            "Direction"	TEXT,
	            "Score"	INTEGER
	            
                    
                )
            """
            con.execute(sql_cmd)
        self.button()


    def button(self):
        self.button = ttk.Button(self.area2, text = "Browse A File",command = self.fileDialog ,width= 50)
        self.button.pack(side= TOP)
        self.button2 = ttk.Button(self.area2, text = "Caucalate Score",command = self.cauculate , width= 50 )
        self.button2.pack(side= TOP)
    
    def fileDialog(self):

        self.filename = filedialog.askopenfilename(initialdir =  "/",multiple=True, title = "Select A File", filetype =
        (("all files","*.*"),("jpeg files","*.jpg"),("png files","*.png"),) )
        #self.label = ttk.Label(self.labelFrame, text = "")
        #self.label.grid(column = 1, row = 2)
        #self.label.configure(text = self.filename)
        self.mycanvas  = tk.Canvas(self.area3 , 
        #bg = 'blue' 
        )
        self.mycanvas.pack(side = TOP  , fill = BOTH,expand = 'yes')
        self.xscrollbar = tk.Scrollbar(self.area3 , orient="horizontal",command=self.mycanvas.xview)
        self.xscrollbar.pack(side = BOTTOM , fill = X)
        self.myFrame = tk.Frame(self.mycanvas , 
        #bg = 'hot pink'
        )
        self.xscrollbar.bind(
            "<Configure>",
            lambda e: self.mycanvas.configure(
                scrollregion=self.mycanvas.bbox("all")
            )
        )
        self.mycanvas.create_window((0, 0), window=self.myFrame
        , anchor='nw'
        )
        for i in range(len(self.filename)):
            img = pim.open(self.filename[i])
            img = img.resize((250, 300), pim.ANTIALIAS)
            photo = ImageTk.PhotoImage(img)
            
            self.label2 = ttk.Button(self.myFrame,image=photo , command = self.showImg)
            self.label2.image = photo 
            self.label2.pack(side = LEFT
            , padx = 20, pady = 20 
            )
        self.mycanvas.configure(xscrollcommand= self.xscrollbar.set)
    def showImg (self):
        popup = Toplevel()
        popup.grab_set()
        popup.configure(bg= "red")
        self.test = Label(popup)
        self.test.pack()
        self.test.configure(text=self.filename)
        
    def cauculate(self):
        #print("Hello")
        r=0
        for i in self.filename:
            img = cv2.imread(i)
            img = cv2.resize(img ,(800,800))
            #cv2.imshow("test",img)
                    
            processed_img = convertImage(img)
            original_img = img.copy()
            contour_img = processed_img.copy()
            area1 = img.copy()
            area2 = img.copy()
            area3 = img.copy()

            contours, heirarchy = cv2.findContours(contour_img,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) # สำคัญตรง RETR
            contours = sorted(contours, key=cv2.contourArea, reverse=True)[0:3] # สำคัญ
            i=0
            squar = []

            for contour in contours:
                p = cv2.arcLength(contour,True)
                approx = cv2.approxPolyDP(contour,0.02*p,True)
                if len(approx) == 4:
                    
                    x,y,w,h = cv2.boundingRect(contour)
                    license_img = original_img[y:y+h,x:x+w]
                    #print(x,y,w,h)
                    squar.append([x,y,w,h])
                    #cv2.imshow("License Detected : ",license_img)
                    cv2.drawContours(img, [contour],-1,(0,255,255),2)
                    #i+=1 
                    #if i ==3 : break
            #cv2.imshow("Image",img)
            #cv2.imshow("Test",processed_img)
            area1 = area1[squar[0][1]:squar[0][1]+squar[0][3] ,  squar[0][0]:squar[0][0]+squar[0][2]  ]
            area2 = area2[squar[1][1]:squar[1][1]+squar[1][3] ,  squar[1][0]:squar[1][0]+squar[1][2]  ]
            area3 = area3[squar[2][1]:squar[2][1]+squar[2][3] ,  squar[2][0]:squar[2][0]+squar[2][2]  ]
            #cv2.imshow("area1",area1)
            #cv2.imshow("area2",area2)
            #cv2.imshow("area3",area3)
            r+=1
            print("filename{}".format(r))
            area = [area1,area2,area3]
            for a in area:
                #print("area")
                img = cv2.resize(a,(582,224))
                numNS = img[64:97,18:75]
                numEW = img[64:97,103:157]
                
                tables = img[153:177,18:87]
                rounds = img[153:177,87:157]

                board1 = img[84:123,169:224]
                contract1=img[84:123,224:296]
                by1=img[84:123,296:324]
                trick1=img[84:123,324:386]
                scoreNS1= img[84:123,386:448]
                scoreEW1 = img[84:123,448:516]

                board2 = img[123:166,169:224]
                contract2=img[123:166,224:296]
                by2=img[123:166,296:324]
                trick2=img[123:166,324:386]
                scoreNS2 = img[123:166,386:448]
                scoreEW2= img[123:166,448:516]

                board3 = img[166:208,169:224]
                contract3=img[166:208,224:296]
                by3=img[166:208,296:324]
                trick3=img[166:208,324:386]
                scoreNS3 = img[166:208,386:448]
                scoreEW3= img[166:208,448:516]
                #with sqlite3.connect("D:\\4thYearKMITL\Project\Reverse1\MY\REAL\\bridgeTs.sqlite") as con:
                #    sql_cmd = """
                #    insert into bridgeTest values(1,'NS',1,1,1,'4H','W',5,100,100)
                 #   """
                #    con.execute(sql_cmd)
                configdigit='--psm 13 --oem 3 -c tessedit_char_whitelist=0123456789'
                numNS = pytesseract.image_to_string(numNS,config= configdigit).strip()
                numNS = numNS.strip('♀.,#')
                if numNS == '':
                    numNS = 0
                numNS = int(numNS)
                #print(numNS)
                numEW = pytesseract.image_to_string(numEW,config= configdigit).strip()
                numEW = numEW.strip('♀.,#')
                if numEW == '':
                    numEW = 0
                numEW = int(numEW)
                board1 = pytesseract.image_to_string(board1,config= configdigit).strip()
                board1 = board1.strip('♀.,#')
                if board1 == '':
                    board1 = 0
                board1 = int(board1)
                board2 = pytesseract.image_to_string(board2,config= configdigit).strip()
                board2 = board2.strip('♀.,#')
                if board2 == '':
                    board2 = 0
                board2 = int(board2)
                board3 = pytesseract.image_to_string(board3,config= configdigit).strip()
                board3 = board3.strip('♀.,#')
                if board3 == '':
                    board3 = 0
                board3 = int(board3)
                scoreNS1 = pytesseract.image_to_string(scoreNS1,config= configdigit).strip()
                scoreNS1 = scoreNS1.strip('♀.,#')
                if scoreNS1 == '':
                    scoreNS1 = 0
                scoreNS1 = int(scoreNS1)
                scoreNS2 = pytesseract.image_to_string(scoreNS2,config= configdigit).strip()
                scoreNS2 = scoreNS2.strip('♀.,#')
                if scoreNS2 == '':
                    scoreNS2 = 0
                scoreNS2 = int(scoreNS2)
                scoreNS3 = pytesseract.image_to_string(scoreNS3,config= configdigit).strip()
                scoreNS3 = scoreNS3.strip('♀.,#')
                if scoreNS3 == '':
                    scoreNS3 = 0
                scoreNS3 = int(scoreNS3)
                scoreEW1 = pytesseract.image_to_string(scoreEW1,config= configdigit).strip()
                scoreEW1 = scoreEW1.strip('♀.,#')
                if scoreEW1 == '':
                    scoreEW1 = 0
                scoreEW1 = int(scoreEW1)
                scoreEW2 = pytesseract.image_to_string(scoreEW2,config= configdigit).strip()
                scoreEW2 = scoreEW2.strip('♀.,#')
                if scoreEW2 == '':
                    scoreEW2 = 0
                scoreEW2 = int(scoreEW2)
                scoreEW3 = pytesseract.image_to_string(scoreEW3,config= configdigit).strip()
                scoreEW3 = scoreEW3.strip('♀.,#')
                if scoreEW3 == '':
                    scoreEW3 = 0
                scoreEW3 = int(scoreEW3)
                with sqlite3.connect("bridgeTeset.sqlite") as con:
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board1, numNS,"NS", scoreNS1))
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board2, numNS,"NS", scoreNS2))
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board3, numNS,"NS", scoreNS3))
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board1, numEW,"EW", scoreEW1))
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board2, numEW,"EW", scoreEW2))
                    
                    con.execute("insert into test (Board, Num, Direction,Score) values (?,?,?,?)",
                    (board3, numEW,"EW", scoreEW3))
        with sqlite3.connect("bridgeTeset.sqlite") as con:
            table = sql.read_sql_query("""
            SELECT Num,Direction,sum(Score) ,DENSE_RANK () OVER ( ORDER BY sum(Score) DESC ) Rank 
	        FROM test 
	        GROUP by Num,Direction      
                
            """, con)
            csvName = 'output.csv'
            table.to_csv(csvName)
            CSV = pd.read_csv(csvName)  
            CSV.to_html("MyCSV.html")  
            path_wkhtmltopdf = r'C:\\Program Files\\wkhtmltopdf\\bin\\wkhtmltopdf.exe'
            config = pdfkit.configuration(wkhtmltopdf=path_wkhtmltopdf)
            pdfkit.from_url("MyCSV.html", "FinalOutput.pdf", configuration=config)
            sql_cmd = """
                    DROP TABLE test

                    """
            con.execute(sql_cmd)


        



        



root = Root()
root.mainloop()