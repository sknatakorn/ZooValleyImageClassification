#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        6
#define COLOR_ORDER    GRB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   20
#define MATRIX_HEIGHT  15
#define MATRIX_TYPE    HORIZONTAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;
CRGB leds2[300];

cLEDText ScrollingMsg;
cLEDText ScrollingMsg2;
const unsigned char TxtDemo[] = {
  EFFECT_FRAME_RATE "\x00"
                                  EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff"
  EFFECT_SCROLL_LEFT "   Hello Mini Project LED Matrix By Natakorn & Thiti"
                                      };
const unsigned char TxtDemo2[] = {
  EFFECT_FRAME_RATE "\x00"
                                  EFFECT_HSV_AV "\x00\xff\xff\xff\xff\xff"
  EFFECT_SCROLL_LEFT "   Good Bye Thank you so much"
                                      };

boolean f1 = false;
boolean f2 = false;
boolean f3 = false;
boolean f4 = false;
boolean f5 = false;
boolean f6 = false;
boolean f7 = false;
int count =0;
void setup()
{  
Serial.begin(9600); 
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(5);
  FastLED.clear(true);
  delay(500);
  

  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 4);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
//  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0x00);

  ScrollingMsg2.SetFont(MatriseFontData);
  ScrollingMsg2.Init(&leds, leds.Width(), ScrollingMsg2.FontHeight() + 1, 0, 4);
  ScrollingMsg2.SetText((unsigned char *)TxtDemo2, sizeof(TxtDemo2) - 1);
}


void loop()
{ int temp = analogRead(A3); //Serial.println(temp); 
int closee = analogRead(A0);//Serial.println(closee); 
int uv = analogRead(A1);// Serial.println(uv);
int rgbran = analogRead(A8); //Serial.println(rgbran); 
if(closee<900 ||f2){f1=false; f2=true;f3=false; f4=true;f7 =false;count=0; FastLED.clear();pacMan();}
if(uv<900||f3){f3=true; f1=false; f2=false; f5=true;f7 =false; if(uv<900){count++; Serial.println(count);if(count%2==0)f3=false; }    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size()); 
 if(f4){ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);ScrollingMsg.UpdateText();f4=false;}
 if (ScrollingMsg.UpdateText() == -1)
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  else
    FastLED.show();
  delay(100);}
 if (count%2==0 && count >0){ f3=false; f1=false; f2=false; f4=true; 
 if(f5){ScrollingMsg2.SetText((unsigned char *)TxtDemo2, sizeof(TxtDemo2) - 1);ScrollingMsg2.UpdateText();f5=false;}
  if (ScrollingMsg2.UpdateText() == -1)
    ScrollingMsg2.SetText((unsigned char *)TxtDemo2, sizeof(TxtDemo2) - 1);
  else
    FastLED.show();
  delay(100);}

   if (temp<900 || f1) {count=0; f1= true; f2=false; f3=false; f4=true; f7 =false;
   draw();
    }
   if (rgbran<900||f7){ count=0;f1=false; f2=false; f3=false; f4=true; f7=true; randomRGB();}

}


void pacMan(){
  FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds2,300);
leds2[280] = CRGB(0, 255, 0);
  leds2[279] = CRGB(0, 255, 0);
  leds2[240] = CRGB(0, 255, 0);
  leds2[239] = CRGB(0, 255, 0);
  leds2[200] = CRGB(0, 255, 0);
  leds2[199] = CRGB(0, 255, 0);
  leds2[160] = CRGB(0, 0, 0);
  leds2[159] = CRGB(0, 0, 0);
  leds2[120] = CRGB(0, 0, 0);
  leds2[119] = CRGB(0, 51, 0);
  leds2[80] = CRGB(0, 255, 0);
  leds2[79] = CRGB(0, 255, 0);
  leds2[40] = CRGB(0, 255, 0);
  leds2[39] = CRGB(0, 255, 0);
  leds2[0] = CRGB(0, 255, 0);
  leds2[1] = CRGB(0, 255, 0);
  leds2[38] = CRGB(0, 255, 0);
  leds2[41] = CRGB(0, 255, 0);
  leds2[78] = CRGB(14, 146, 0);
  leds2[81] = CRGB(152, 152, 0);
  leds2[118] = CRGB(255, 255, 0);
  leds2[121] = CRGB(255, 255, 0);
  leds2[158] = CRGB(255, 255, 0);
  leds2[161] = CRGB(255, 255, 0);
  leds2[198] = CRGB(255, 255, 44);
  leds2[201] = CRGB(255, 255, 255);
  leds2[238] = CRGB(34, 34, 34);
  leds2[241] = CRGB(0, 241, 0);
  leds2[278] = CRGB(0, 255, 0);
  leds2[281] = CRGB(0, 255, 0);
  leds2[282] = CRGB(0, 255, 0);
  leds2[277] = CRGB(0, 255, 0);
  leds2[242] = CRGB(18, 155, 0);
  leds2[237] = CRGB(255, 255, 0);
  leds2[202] = CRGB(255, 255, 0);
  leds2[197] = CRGB(255, 255, 0);
  leds2[162] = CRGB(255, 255, 0);
  leds2[157] = CRGB(255, 255, 0);
  leds2[122] = CRGB(255, 255, 0);
  leds2[117] = CRGB(255, 255, 0);
  leds2[82] = CRGB(255, 255, 0);
  leds2[77] = CRGB(255, 255, 87);
  leds2[42] = CRGB(143, 143, 116);
  leds2[37] = CRGB(0, 237, 0);
  leds2[2] = CRGB(0, 255, 0);
  leds2[3] = CRGB(0, 255, 0);
  leds2[36] = CRGB(14, 146, 0);
  leds2[43] = CRGB(255, 255, 0);
  leds2[76] = CRGB(255, 255, 0);
  leds2[83] = CRGB(255, 255, 0);
  leds2[116] = CRGB(255, 255, 0);
  leds2[123] = CRGB(255, 255, 0);
  leds2[156] = CRGB(255, 255, 0);
  leds2[163] = CRGB(255, 255, 0);
  leds2[196] = CRGB(255, 255, 0);
  leds2[203] = CRGB(255, 255, 0);
  leds2[236] = CRGB(255, 255, 0);
  leds2[243] = CRGB(255, 255, 92);
  leds2[276] = CRGB(143, 143, 143);
  leds2[283] = CRGB(0, 241, 0);
  leds2[284] = CRGB(0, 255, 0);
  leds2[275] = CRGB(152, 152, 0);
  leds2[244] = CRGB(255, 255, 0);
  leds2[235] = CRGB(255, 255, 0);
  leds2[204] = CRGB(255, 255, 0);
  leds2[195] = CRGB(255, 255, 0);
  leds2[164] = CRGB(255, 255, 0);
  leds2[155] = CRGB(255, 255, 0);
  leds2[124] = CRGB(255, 255, 0);
  leds2[115] = CRGB(255, 255, 0);
  leds2[84] = CRGB(255, 255, 0);
  leds2[75] = CRGB(255, 255, 0);
  leds2[44] = CRGB(255, 255, 0);
  leds2[35] = CRGB(255, 255, 87);
  leds2[4] = CRGB(18, 121, 18);
  leds2[5] = CRGB(0, 255, 0);
  leds2[34] = CRGB(255, 255, 0);
  leds2[45] = CRGB(255, 255, 0);
  leds2[74] = CRGB(255, 255, 0);
  leds2[85] = CRGB(255, 255, 0);
  leds2[114] = CRGB(255, 255, 0);
  leds2[125] = CRGB(255, 255, 0);
  leds2[154] = CRGB(255, 255, 0);
  leds2[165] = CRGB(255, 255, 0);
  leds2[194] = CRGB(255, 255, 0);
  leds2[205] = CRGB(255, 255, 0);
  leds2[234] = CRGB(255, 255, 0);
  leds2[245] = CRGB(255, 255, 0);
  leds2[274] = CRGB(255, 255, 0);
  leds2[285] = CRGB(34, 34, 34);
  leds2[286] = CRGB(0, 0, 0);
  leds2[273] = CRGB(255, 255, 0);
  leds2[246] = CRGB(255, 255, 0);
  leds2[233] = CRGB(255, 255, 0);
  leds2[206] = CRGB(255, 255, 0);
  leds2[193] = CRGB(255, 255, 0);
  leds2[166] = CRGB(255, 255, 0);
  leds2[153] = CRGB(255, 255, 0);
  leds2[126] = CRGB(255, 255, 0);
  leds2[113] = CRGB(255, 255, 0);
  leds2[86] = CRGB(255, 255, 0);
  leds2[73] = CRGB(160, 160, 0);
  leds2[46] = CRGB(173, 173, 0);
  leds2[33] = CRGB(255, 255, 0);
  leds2[6] = CRGB(255, 255, 0);
  leds2[7] = CRGB(0, 0, 0);
  leds2[32] = CRGB(255, 255, 0);
  leds2[47] = CRGB(255, 255, 0);
  leds2[72] = CRGB(255, 255, 0);
  leds2[87] = CRGB(255, 255, 0);
  leds2[112] = CRGB(255, 255, 0);
  leds2[127] = CRGB(255, 255, 0);
  leds2[152] = CRGB(255, 255, 0);
  leds2[167] = CRGB(255, 255, 0);
  leds2[192] = CRGB(255, 255, 0);
  leds2[207] = CRGB(255, 255, 0);
  leds2[232] = CRGB(0, 0, 0);
  leds2[247] = CRGB(0, 0, 0);
  leds2[272] = CRGB(255, 255, 0);
  leds2[287] = CRGB(255, 255, 0);
  leds2[288] = CRGB(0, 0, 0);
  leds2[271] = CRGB(255, 255, 0);
  leds2[248] = CRGB(255, 255, 0);
  leds2[231] = CRGB(255, 255, 0);
  leds2[208] = CRGB(255, 255, 0);
  leds2[191] = CRGB(255, 255, 0);
  leds2[168] = CRGB(255, 255, 0);
  leds2[151] = CRGB(16, 32, 0);
  leds2[128] = CRGB(28, 28, 12);
  leds2[111] = CRGB(255, 255, 0);
  leds2[88] = CRGB(255, 255, 0);
  leds2[71] = CRGB(255, 255, 0);
  leds2[48] = CRGB(255, 255, 0);
  leds2[31] = CRGB(255, 255, 0);
  leds2[8] = CRGB(255, 255, 0);
  leds2[9] = CRGB(40, 40, 40);
  leds2[30] = CRGB(151, 151, 0);
  leds2[49] = CRGB(255, 255, 0);
  leds2[70] = CRGB(255, 255, 0);
  leds2[89] = CRGB(255, 255, 0);
  leds2[110] = CRGB(255, 255, 0);
  leds2[129] = CRGB(41, 82, 0);
  leds2[150] = CRGB(0, 255, 0);
  leds2[169] = CRGB(11, 252, 11);
  leds2[190] = CRGB(73, 73, 32);
  leds2[209] = CRGB(255, 255, 0);
  leds2[230] = CRGB(255, 255, 0);
  leds2[249] = CRGB(255, 255, 0);
  leds2[270] = CRGB(255, 255, 0);
  leds2[289] = CRGB(211, 211, 0);
  leds2[290] = CRGB(199, 199, 199);
  leds2[269] = CRGB(128, 128, 0);
  leds2[250] = CRGB(255, 255, 0);
  leds2[229] = CRGB(255, 255, 0);
  leds2[210] = CRGB(255, 255, 0);
  leds2[189] = CRGB(57, 113, 0);
  leds2[170] = CRGB(0, 255, 0);
  leds2[149] = CRGB(0, 255, 0);
  leds2[130] = CRGB(0, 255, 0);
  leds2[109] = CRGB(27, 248, 27);
  leds2[90] = CRGB(101, 101, 44);
  leds2[69] = CRGB(255, 255, 0);
  leds2[50] = CRGB(255, 255, 0);
  leds2[29] = CRGB(255, 255, 0);
  leds2[10] = CRGB(34, 34, 0);
  leds2[11] = CRGB(0, 255, 0);
  leds2[28] = CRGB(16, 16, 0);
  leds2[51] = CRGB(136, 136, 0);
  leds2[68] = CRGB(255, 255, 0);
  leds2[91] = CRGB(63, 127, 0);
  leds2[108] = CRGB(0, 255, 0);
  leds2[131] = CRGB(0, 255, 0);
  leds2[148] = CRGB(0, 255, 0);
  leds2[171] = CRGB(0, 255, 0);
  leds2[188] = CRGB(0, 255, 0);
  leds2[211] = CRGB(35, 245, 35);
  leds2[228] = CRGB(113, 113, 50);
  leds2[251] = CRGB(255, 255, 0);
  leds2[268] = CRGB(255, 255, 0);
  leds2[291] = CRGB(0, 221, 0);
  leds2[292] = CRGB(0, 255, 0);
  leds2[267] = CRGB(85, 218, 85);
  leds2[252] = CRGB(73, 73, 0);
  leds2[227] = CRGB(22, 84, 0);
  leds2[212] = CRGB(0, 255, 0);
  leds2[187] = CRGB(0, 255, 0);
  leds2[172] = CRGB(0, 255, 0);
  leds2[147] = CRGB(0, 255, 0);
  leds2[132] = CRGB(0, 255, 0);
  leds2[107] = CRGB(0, 255, 0);
  leds2[92] = CRGB(0, 255, 0);
  leds2[67] = CRGB(37, 245, 37);
  leds2[52] = CRGB(109, 109, 48);
  leds2[27] = CRGB(27, 139, 0);
  leds2[12] = CRGB(0, 255, 0);
  leds2[13] = CRGB(0, 255, 0);
  leds2[26] = CRGB(0, 255, 0);
  leds2[53] = CRGB(39, 226, 39);
  leds2[66] = CRGB(0, 255, 0);
  leds2[93] = CRGB(0, 255, 0);
  leds2[106] = CRGB(0, 255, 0);
  leds2[133] = CRGB(0, 255, 0);
  leds2[146] = CRGB(0, 255, 0);
  leds2[173] = CRGB(0, 255, 0);
  leds2[186] = CRGB(0, 255, 0);
  leds2[213] = CRGB(0, 255, 0);
  leds2[226] = CRGB(0, 255, 0);
  leds2[253] = CRGB(32, 246, 32);
  leds2[266] = CRGB(0, 255, 0);
  leds2[293] = CRGB(0, 255, 0);
  leds2[294] = CRGB(0, 255, 0);
  leds2[265] = CRGB(0, 255, 0);
  leds2[254] = CRGB(0, 255, 0);
  leds2[225] = CRGB(0, 255, 0);
  leds2[214] = CRGB(0, 255, 0);
  leds2[185] = CRGB(0, 255, 0);
  leds2[174] = CRGB(0, 255, 0);
  leds2[145] = CRGB(0, 255, 0);
  leds2[134] = CRGB(0, 255, 0);
  leds2[105] = CRGB(0, 255, 0);
  leds2[94] = CRGB(0, 255, 0);
  leds2[65] = CRGB(0, 255, 0);
  leds2[54] = CRGB(0, 255, 0);
  leds2[25] = CRGB(0, 255, 0);
  leds2[14] = CRGB(0, 255, 0);
  leds2[262]=CRGB(255,0,0);
leds2[224]=CRGB(255,0,0);
leds2[223]=CRGB(255,0,0);
leds2[222]=CRGB(255,0,0);
leds2[221]=CRGB(255,0,0);
leds2[220]=CRGB(255,0,0);
leds2[215]=CRGB(255,0,0);
leds2[216]=CRGB(255,255,255);
leds2[217]=CRGB(255,0,0);
leds2[218]=CRGB(255,255,255);
leds2[219]=CRGB(255,0,0);
leds2[184]=CRGB(255,0,0);
leds2[183]=CRGB(0,0,0);
leds2[182]=CRGB(255,0,0);
leds2[181]=CRGB(0,0,0);
leds2[180]=CRGB(255,0,0);
leds2[175]=CRGB(255,0,0);
leds2[176]=CRGB(255,255,255);
leds2[177]=CRGB(255,0,0);
leds2[178]=CRGB(255,255,255);
leds2[179]=CRGB(255,0,0);
leds2[144]=CRGB(255,0,0);
leds2[143]=CRGB(255,0,0);
leds2[142]=CRGB(255,0,0);
leds2[141]=CRGB(255,0,0);
leds2[140]=CRGB(255,0,0);
leds2[135]=CRGB(255,0,0);
leds2[136]=CRGB(255,0,0);
leds2[137]=CRGB(255,0,0);
leds2[138]=CRGB(255,0,0);
leds2[139]=CRGB(255,0,0);
leds2[104]=CRGB(255,0,0);
leds2[103]=CRGB(255,0,0);
leds2[102]=CRGB(255,0,0);
leds2[101]=CRGB(255,0,0);
leds2[100]=CRGB(255,0,0);
leds2[95]=CRGB(255,0,0);
leds2[96]=CRGB(255,0,0);
leds2[97]=CRGB(255,0,0);
leds2[98]=CRGB(255,0,0);
leds2[99]=CRGB(255,0,0);
leds2[64]=CRGB(255,0,0);
leds2[63]=CRGB(255,0,0);
leds2[62]=CRGB(255,0,0);
leds2[61]=CRGB(255,0,0);
leds2[60]=CRGB(255,0,0);
leds2[55]=CRGB(255,0,0);
leds2[57]=CRGB(255,0,0);
leds2[59]=CRGB(255,0,0);
leds2[24]=CRGB(255,0,0);
leds2[22]=CRGB(255,0,0);
leds2[20]=CRGB(255,0,0);
  FastLED.show();
  delay(100);
   leds2[280] = CRGB(0, 0, 0);
  leds2[279] = CRGB(0, 0, 0);
  leds2[240] = CRGB(0, 0, 0);
  leds2[239] = CRGB(0, 0, 0);
  leds2[200] = CRGB(0, 0, 0);
  leds2[199] = CRGB(0, 0, 0);
  leds2[119] = CRGB(0, 0, 0);
  leds2[80] = CRGB(0, 0, 0);
  leds2[79] = CRGB(0, 0, 0);
  leds2[40] = CRGB(0, 0, 0);
  leds2[39] = CRGB(0, 0, 0);
  leds2[0] = CRGB(0, 0, 0);
  leds2[1] = CRGB(0, 0, 0);
  leds2[38] = CRGB(0, 0, 0);
  leds2[41] = CRGB(0, 0, 0);
  leds2[78] = CRGB(14, 14, 0);
  leds2[241] = CRGB(0, 0, 0);
  leds2[278] = CRGB(0, 0, 0);
  leds2[281] = CRGB(0, 0, 0);
  leds2[82] = CRGB(0, 0, 0);
  leds2[77] = CRGB(0, 0, 0);
  leds2[42] = CRGB(18, 18, 0);
  leds2[37] = CRGB(0, 0, 0);
  leds2[2] = CRGB(0, 0, 0);
  leds2[3] = CRGB(0, 0, 0);
  leds2[36] = CRGB(14, 14, 0);
  leds2[283] = CRGB(0, 0, 0);
  leds2[284] = CRGB(0, 0, 0);
  leds2[4] = CRGB(18, 18, 18);
  leds2[95] = CRGB(0, 0, 0);
  leds2[151] = CRGB(255, 255, 0);
  leds2[128] = CRGB(255, 255, 0);
  leds2[129] = CRGB(255, 255, 0);
  leds2[150] = CRGB(255, 255, 0);
  leds2[169] = CRGB(255, 255, 0);
  leds2[190] = CRGB(255, 255, 0);
  leds2[189] = CRGB(255, 255, 0);
  leds2[170] = CRGB(255, 255, 0);
  leds2[149] = CRGB(255, 255, 0);
  leds2[130] = CRGB(255, 255, 0);
  leds2[109] = CRGB(255, 255, 0);
  leds2[90] = CRGB(255, 255, 0);
  leds2[11] = CRGB(0, 0, 0);
  leds2[91] = CRGB(255, 255, 0);
  leds2[108] = CRGB(255, 255, 0);
  leds2[131] = CRGB(255, 255, 0);
  leds2[148] = CRGB(255, 255, 0);
  leds2[171] = CRGB(255, 255, 0);
  leds2[188] = CRGB(255, 255, 0);
  leds2[211] = CRGB(255, 255, 0);
  leds2[228] = CRGB(255, 255, 0);
  leds2[291] = CRGB(0, 0, 0);
  leds2[292] = CRGB(0, 0, 0);
  leds2[267] = CRGB(85, 85, 85);
  leds2[227] = CRGB(215, 215, 0);
  leds2[212] = CRGB(255, 255, 0);
  leds2[187] = CRGB(255, 255, 0);
  leds2[172] = CRGB(255, 255, 0);
  leds2[147] = CRGB(255, 255, 0);
  leds2[132] = CRGB(255, 255, 0);
  leds2[107] = CRGB(255, 255, 0);
  leds2[92] = CRGB(255, 255, 0);
  leds2[67] = CRGB(255, 255, 0);
  leds2[52] = CRGB(255, 255, 0);
  leds2[27] = CRGB(27, 27, 0);
  leds2[12] = CRGB(0, 0, 0);
  leds2[13] = CRGB(0, 0, 0);
  leds2[26] = CRGB(0, 0, 0);
  leds2[53] = CRGB(78, 78, 78);
  leds2[66] = CRGB(67, 67, 0);
  leds2[93] = CRGB(200, 200, 0);
  leds2[106] = CRGB(255, 255, 0);
  leds2[133] = CRGB(255, 255, 0);
  leds2[146] = CRGB(255, 255, 0);
  leds2[173] = CRGB(255, 255, 0);
  leds2[186] = CRGB(255, 255, 0);
  leds2[213] = CRGB(255, 255, 0);
  leds2[226] = CRGB(255, 255, 0);
  leds2[253] = CRGB(27, 27, 0);
  leds2[266] = CRGB(0, 0, 0);
  leds2[293] = CRGB(0, 0, 0);
  leds2[294] = CRGB(0, 0, 0);
  leds2[265] = CRGB(0, 0, 0);
  leds2[254] = CRGB(0, 0, 0);
  leds2[225] = CRGB(0, 0, 0);
  leds2[214] = CRGB(10, 10, 0);
  leds2[185] = CRGB(34, 34, 0);
  leds2[174] = CRGB(255, 255, 0);
  leds2[145] = CRGB(255, 255, 0);
  leds2[134] = CRGB(255, 255, 0);
  leds2[105] = CRGB(211, 211, 0);
  leds2[94] = CRGB(34, 34, 0);
  leds2[65] = CRGB(0, 0, 0);
  leds2[54] = CRGB(0, 0, 0);
  leds2[25] = CRGB(0, 0, 0);
  leds2[14] = CRGB(0, 0, 0);
  leds2[262]=CRGB(255,0,0);
leds2[224]=CRGB(255,0,0);
leds2[223]=CRGB(255,0,0);
leds2[222]=CRGB(255,0,0);
leds2[221]=CRGB(255,0,0);
leds2[220]=CRGB(255,0,0);
leds2[215]=CRGB(255,0,0);
leds2[216]=CRGB(255,255,255);
leds2[217]=CRGB(255,0,0);
leds2[218]=CRGB(255,255,255);
leds2[219]=CRGB(255,0,0);
leds2[184]=CRGB(255,0,0);
leds2[183]=CRGB(0,0,0);
leds2[182]=CRGB(255,0,0);
leds2[181]=CRGB(0,0,0);
leds2[180]=CRGB(255,0,0);
leds2[175]=CRGB(255,0,0);
leds2[176]=CRGB(255,255,255);
leds2[177]=CRGB(255,0,0);
leds2[178]=CRGB(255,255,255);
leds2[179]=CRGB(255,0,0);
leds2[144]=CRGB(255,0,0);
leds2[143]=CRGB(255,0,0);
leds2[142]=CRGB(255,0,0);
leds2[141]=CRGB(255,0,0);
leds2[140]=CRGB(255,0,0);
leds2[135]=CRGB(255,0,0);
leds2[136]=CRGB(255,0,0);
leds2[137]=CRGB(255,0,0);
leds2[138]=CRGB(255,0,0);
leds2[139]=CRGB(255,0,0);
leds2[104]=CRGB(255,0,0);
leds2[103]=CRGB(255,0,0);
leds2[102]=CRGB(255,0,0);
leds2[101]=CRGB(255,0,0);
leds2[100]=CRGB(255,0,0);
leds2[95]=CRGB(255,0,0);
leds2[96]=CRGB(255,0,0);
leds2[97]=CRGB(255,0,0);
leds2[98]=CRGB(255,0,0);
leds2[99]=CRGB(255,0,0);
leds2[64]=CRGB(255,0,0);
leds2[63]=CRGB(255,0,0);
leds2[62]=CRGB(255,0,0);
leds2[61]=CRGB(255,0,0);
leds2[60]=CRGB(255,0,0);
leds2[262]=CRGB(255,0,0);
leds2[224]=CRGB(255,0,0);
leds2[223]=CRGB(255,0,0);
leds2[222]=CRGB(255,0,0);
leds2[221]=CRGB(255,0,0);
leds2[220]=CRGB(255,0,0);
leds2[215]=CRGB(255,0,0);
leds2[216]=CRGB(255,255,255);
leds2[217]=CRGB(255,0,0);
leds2[218]=CRGB(255,255,255);
leds2[219]=CRGB(255,0,0);
leds2[184]=CRGB(255,0,0);
leds2[183]=CRGB(0,0,0);
leds2[182]=CRGB(255,0,0);
leds2[181]=CRGB(0,0,0);
leds2[180]=CRGB(255,0,0);
leds2[175]=CRGB(255,0,0);
leds2[176]=CRGB(255,255,255);
leds2[177]=CRGB(255,0,0);
leds2[178]=CRGB(255,255,255);
leds2[179]=CRGB(255,0,0);
leds2[144]=CRGB(255,0,0);
leds2[143]=CRGB(255,0,0);
leds2[142]=CRGB(255,0,0);
leds2[141]=CRGB(255,0,0);
leds2[140]=CRGB(255,0,0);
leds2[135]=CRGB(255,0,0);
leds2[136]=CRGB(255,0,0);
leds2[137]=CRGB(255,0,0);
leds2[138]=CRGB(255,0,0);
leds2[139]=CRGB(255,0,0);
leds2[104]=CRGB(255,0,0);
leds2[103]=CRGB(255,0,0);
leds2[102]=CRGB(255,0,0);
leds2[101]=CRGB(255,0,0);
leds2[100]=CRGB(255,0,0);
leds2[95]=CRGB(255,0,0);
leds2[96]=CRGB(255,0,0);
leds2[97]=CRGB(255,0,0);
leds2[98]=CRGB(255,0,0);
leds2[99]=CRGB(255,0,0);
leds2[64]=CRGB(255,0,0);
leds2[63]=CRGB(255,0,0);
leds2[62]=CRGB(255,0,0);
leds2[61]=CRGB(255,0,0);
leds2[60]=CRGB(255,0,0);
leds2[56]=CRGB(255,0,0);
leds2[58]=CRGB(255,0,0);
leds2[23]=CRGB(255,0,0);
leds2[21]=CRGB(255,0,0);

  FastLED.show();
  delay(100);

}

void circle(){  FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds2,300);

  leds2[248] = CRGB(255, 0, 0);
  leds2[249] = CRGB(255, 0, 0);
  leds2[250] = CRGB(255, 0, 0);
  leds2[233] = CRGB(255, 0, 0);  
  leds2[232] = CRGB(255, 0, 0);
  leds2[231] = CRGB(255, 0, 0);
  leds2[230] = CRGB(255, 0, 0);
  leds2[229] = CRGB(255, 0, 0); 
leds2[228] = CRGB(255, 0, 0);
  leds2[227] = CRGB(255, 0, 0);
  leds2[205] = CRGB(255, 0, 0);
  leds2[206] = CRGB(255, 0, 0); 
  leds2[207] = CRGB(255, 0, 0);
  leds2[208] = CRGB(255, 0, 0);
  leds2[209] = CRGB(255, 0, 0);
  leds2[210] = CRGB(255, 0, 0); 
  leds2[211] = CRGB(255, 0, 0);
  leds2[212] = CRGB(255, 0, 0);
  leds2[213] = CRGB(255, 0, 0);
  leds2[195] = CRGB(255, 0, 0); 
  leds2[194] = CRGB(255, 0, 0);
  leds2[193] = CRGB(255, 0, 0);
  leds2[192] = CRGB(255, 0, 0);
  leds2[191] = CRGB(255, 0, 0); 
   leds2[190] = CRGB(255, 0, 0);
  leds2[189] = CRGB(255, 0, 0);
  leds2[188] = CRGB(255, 0, 0);
  leds2[187] = CRGB(255, 0, 0);
    leds2[186] = CRGB(255, 0, 0);
  leds2[185] = CRGB(255, 0, 0);
  leds2[164] = CRGB(255, 0, 0);
  leds2[165] = CRGB(255, 0, 0);
    leds2[166] = CRGB(255, 0, 0);
  leds2[167] = CRGB(255, 0, 0);
  leds2[168] = CRGB(255, 0, 0);
  leds2[169] = CRGB(255, 0, 0);
    leds2[170] = CRGB(255, 0, 0);
  leds2[171] = CRGB(255, 0, 0);
  leds2[172] = CRGB(255, 0, 0);
  leds2[173] = CRGB(255, 0, 0);
    leds2[174] = CRGB(255, 0, 0);
  leds2[155] = CRGB(255, 0, 0);
  leds2[154] = CRGB(255, 0, 0);
  leds2[153] = CRGB(255, 0, 0);
    leds2[152] = CRGB(255, 0, 0);
  leds2[151] = CRGB(255, 0, 0);
  leds2[150] = CRGB(255, 0, 0);
  leds2[149] = CRGB(255, 0, 0);
    leds2[148] = CRGB(255, 0, 0);
  leds2[147] = CRGB(255, 0, 0);
  leds2[146] = CRGB(255, 0, 0);
  leds2[145] = CRGB(255, 0, 0);
    leds2[124] = CRGB(255, 0, 0);
  leds2[125] = CRGB(255, 0, 0);
  leds2[126] = CRGB(255, 0, 0);
  leds2[127] = CRGB(255, 0, 0);
   leds2[128] = CRGB(255, 0, 0);
  leds2[129] = CRGB(255, 0, 0);
  leds2[130] = CRGB(255, 0, 0);
  leds2[131] = CRGB(255, 0, 0); 
    leds2[132] = CRGB(255, 0, 0);
  leds2[133] = CRGB(255, 0, 0);
  leds2[134] = CRGB(255, 0, 0);
  leds2[115] = CRGB(255, 0, 0);
  leds2[114] = CRGB(255, 0, 0);
    leds2[113] = CRGB(255, 0, 0);
  leds2[112] = CRGB(255, 0, 0);
  leds2[111] = CRGB(255, 0, 0);
  leds2[110] = CRGB(255, 0, 0);
    leds2[109] = CRGB(255, 0, 0);
  leds2[108] = CRGB(255, 0, 0);
  leds2[107] = CRGB(255, 0, 0);
  leds2[106] = CRGB(255, 0, 0);
    leds2[105] = CRGB(255, 0, 0);
  leds2[86] = CRGB(255, 0, 0);
  leds2[85] = CRGB(255, 0, 0);
  leds2[87] = CRGB(255, 0, 0);
  leds2[88] = CRGB(255, 0, 0);
   leds2[89] = CRGB(255, 0, 0);
  leds2[90] = CRGB(255, 0, 0);
  leds2[91] = CRGB(255, 0, 0);
  leds2[92] = CRGB(255, 0, 0); 
    leds2[93] = CRGB(255, 0, 0);
  leds2[73] = CRGB(255, 0, 0);
  leds2[72] = CRGB(255, 0, 0);
  leds2[71] = CRGB(255, 0, 0);
    leds2[70] = CRGB(255, 0, 0);
  leds2[69] = CRGB(255, 0, 0);
  leds2[68] = CRGB(255, 0, 0);
  leds2[67] = CRGB(255, 0, 0);
    leds2[48] = CRGB(255, 0, 0);
  leds2[49] = CRGB(255, 0, 0);
  leds2[50] = CRGB(255, 0, 0);
  FastLED.show();
  }
void japanflag(){
  for(int i = 0 ; i<300;i++)
  leds2[i] =CRGB(255,255,255);
  circle(); 
  
  }
void rect(){
    leds2[244] = CRGB(0, 255, 0);
    leds2[245] = CRGB(0, 255, 0);
  leds2[246] = CRGB(0, 255, 0);
  leds2[247] = CRGB(0, 255, 0);
  leds2[251] = CRGB(0, 255, 0);
    leds2[252] = CRGB(0, 255, 0);
  leds2[253] = CRGB(0, 255, 0);
  leds2[254] = CRGB(0, 255, 0);
  leds2[235] = CRGB(0, 255, 0);
    leds2[234] = CRGB(0, 255, 0);
  leds2[226] = CRGB(0, 255, 0);
  leds2[225] = CRGB(0, 255, 0);
  leds2[204] = CRGB(0, 255, 0);
    leds2[214] = CRGB(0, 255, 0);
  leds2[84] = CRGB(0, 255, 0);
  leds2[94] = CRGB(0, 255, 0);
  leds2[74] = CRGB(0, 255, 0);
    leds2[75] = CRGB(0, 255, 0);
  leds2[66] = CRGB(0, 255, 0);
  leds2[65] = CRGB(0, 255, 0);
   leds2[45] = CRGB(0, 255, 0);
    leds2[46] = CRGB(0, 255, 0);
  leds2[47] = CRGB(0, 255, 0);
  leds2[44] = CRGB(0, 255, 0);
   leds2[51] = CRGB(0, 255, 0);
    leds2[52] = CRGB(0, 255, 0);
  leds2[53] = CRGB(0, 255, 0);
  leds2[54] = CRGB(0, 255, 0);
  circle();
  }

  void tri(){ FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds2,300);
      leds2[73] = CRGB(255, 0, 0);
  leds2[72] = CRGB(255, 0, 0);
  leds2[71] = CRGB(255, 0, 0);
    leds2[70] = CRGB(255, 0, 0);
  leds2[69] = CRGB(255, 0, 0);
  leds2[68] = CRGB(255, 0, 0);
  leds2[67] = CRGB(255, 0, 0);
    leds2[66] = CRGB(0, 255, 0);
    leds2[74] = CRGB(0, 255, 0);
    leds2[48] = CRGB(255, 0, 0);
  leds2[49] = CRGB(255, 0, 0);
  leds2[50] = CRGB(255, 0, 0);
  leds2[45] = CRGB(0, 255, 0);
    leds2[46] = CRGB(0, 255, 0);
  leds2[47] = CRGB(0, 255, 0);
  leds2[44] = CRGB(0, 255, 0);
   leds2[51] = CRGB(0, 255, 0);
    leds2[52] = CRGB(0, 255, 0);
  leds2[53] = CRGB(0, 255, 0);
  leds2[54] = CRGB(0, 255, 0);  
    leds2[86] = CRGB(255, 0, 0);
  
  leds2[87] = CRGB(255, 0, 0);
  leds2[88] = CRGB(255, 0, 0);
   leds2[89] = CRGB(255, 0, 0);
  leds2[90] = CRGB(255, 0, 0);
  leds2[91] = CRGB(255, 0, 0);
  leds2[92] = CRGB(255, 0, 0); 
    leds2[112] = CRGB(255, 0, 0);
  leds2[111] = CRGB(255, 0, 0);
  leds2[110] = CRGB(255, 0, 0);
    leds2[109] = CRGB(255, 0, 0);
  leds2[108] = CRGB(255, 0, 0);
   leds2[128] = CRGB(255, 0, 0);
  leds2[129] = CRGB(255, 0, 0);
  leds2[130] = CRGB(255, 0, 0);
    leds2[150] = CRGB(255, 0, 0);

    leds2[244] = CRGB(0, 255, 0);
    leds2[245] = CRGB(0, 255, 0);
  leds2[246] = CRGB(0, 255, 0);
  leds2[247] = CRGB(0, 255, 0);
  leds2[251] = CRGB(0, 255, 0);
    leds2[252] = CRGB(0, 255, 0);
  leds2[253] = CRGB(0, 255, 0);
  leds2[254] = CRGB(0, 255, 0);
    leds2[248] = CRGB(255, 0, 0);
  leds2[249] = CRGB(255, 0, 0);
  leds2[250] = CRGB(255, 0, 0);
  leds2[233] = CRGB(255, 0, 0);  
  leds2[232] = CRGB(255, 0, 0);
  leds2[231] = CRGB(255, 0, 0);
  leds2[230] = CRGB(255, 0, 0);
  leds2[229] = CRGB(255, 0, 0); 
leds2[228] = CRGB(255, 0, 0);
  leds2[227] = CRGB(255, 0, 0);
   leds2[234] = CRGB(0, 255, 0);
  leds2[226] = CRGB(0, 255, 0);
  

      leds2[206] = CRGB(255, 0, 0); 
  leds2[207] = CRGB(255, 0, 0);
  leds2[208] = CRGB(255, 0, 0);
  leds2[209] = CRGB(255, 0, 0);
  leds2[210] = CRGB(255, 0, 0); 
  leds2[211] = CRGB(255, 0, 0);
  leds2[212] = CRGB(255, 0, 0);
    leds2[192] = CRGB(255, 0, 0);
  leds2[191] = CRGB(255, 0, 0); 
   leds2[190] = CRGB(255, 0, 0);
  leds2[189] = CRGB(255, 0, 0);
  leds2[188] = CRGB(255, 0, 0);  
  leds2[168] = CRGB(255, 0, 0);
  leds2[169] = CRGB(255, 0, 0);
    leds2[170] = CRGB(255, 0, 0);  
    FastLED.show();
    }

    void thaiflag(){
  FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds2,300);    
      for(int i = 0 ;i<=59;i++)leds2[i] = CRGB(255,0,0); 
      for(int i = 60 ;i<=99;i++)leds2[i] = CRGB(255,255,255); 
      for(int i = 100 ;i<=199;i++)leds2[i] = CRGB(0,0,255); 
      for(int i = 200 ;i<=239;i++)leds2[i] = CRGB(255,255,255); 
      for(int i = 240 ;i<=299;i++)leds2[i] = CRGB(255,0,0); 
     FastLED.show();
      }

   void randomRGB(){
     FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds2,300);  
    for(int i = 0 ; i<300;i++){leds2[i]=CRGB::Pink; FastLED.show();}
    for(int i = 299 ; i>=0;i--){leds2[i]=CRGB::Chocolate; FastLED.show();}
    for(int i = 150 ; i<300;i++){leds2[i]=CRGB::Black; FastLED.show();}
    for(int i = 150 ; i>=0;i--){leds2[i]=CRGB::Black; FastLED.show();}
    FastLED.showColor(CRGB::Red);
  delay(500);
  FastLED.showColor(CRGB::Lime);
  delay(500);
  FastLED.showColor(CRGB::Blue);
  delay(500);
  FastLED.showColor(CRGB::White);
  delay(500);
  FastLED.showColor(CRGB::Black);
  delay(500);  
    
    
    }
    void draw(){
      FastLED.clear(); circle(); delay(2000);FastLED.clear(); rect(); delay(2000);FastLED.clear(); tri();delay(2000);FastLED.clear(); japanflag(); delay(2000);FastLED.clear();
    thaiflag(); delay(2000);FastLED.clear();}
