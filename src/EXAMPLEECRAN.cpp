// // #include "color.h"

// // #include "LSD.h"
// // #include <iostream>
// // #include "EPaper.h"

// // byte *gammatable = new byte[256];
// // Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// // int *colorInfo = new int[3];

// // // void setup()
// // // {
// // //   delay(2000);
// // //   // ColorSetup(gammatable, &tcs);
// // //   // SDsetup();
// // // }


// // // void loop()
// // // {
// // //   delay(100);
// // //   // ColorRead(gammatable, &tcs, colorInfo);
// // //   // SDwrite(String(colorInfo[0]) + ";" + String(colorInfo[1]) + ";" + String(colorInfo[2]) + ";\n");
// // //   // SDwriteBullshit(String("bullshit ; ; ;"));

// // // }



// // #include <Arduino.h>
// // #include <SPI.h>
// // #include "epd2in13_V2.h"
// // #include "epdpaint.h"
// // #include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/bitmaps/Bitmaps128x250.h"
// #include "imagedata.h"
// #include "Ecran.h"
// #include <string>

// // #include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/epd/GxEPD2_213.h"
// // GxEPD2_213 _ECRAN(D10, D9, D8, D7);
// // u_int8_t _BMP[(250*128)/8];
// // Paint paintTest(_BMP, 122, 250);

// // void setup()
// // {

// //   _ECRAN.init();
// //   // comment out next line to have no or minimal Adafruit_GFX code
// //   _ECRAN.setTextColor(GxEPD_BLACK);
// //   _ECRAN.firstPage();
// //   do
// //   {
// //     _ECRAN.fillScreen(GxEPD_WHITE);
// //     // comment out next line to have no or minimal Adafruit_GFX code
// //     _ECRAN.print("Hello World!");
// //   }
// //   while (_ECRAN.nextPage());
// // }

// // void loop()
// // {

// // }

// // Ecran _ECRAN;

// // void setup()
// // {
// //   _ECRAN.Initialiser();
// //   delay(2000);
// //   // _ECRAN.InitialiserPartiellement();
// //   // _ECRAN.AfficherNom();
// // }

// // void loop()
// // {
 
// // }





// #define ENABLE_GxEPD2_GFX 0
// #define DISP GxEPD2_213_B72
// #define BLANC 1
// #define NOIR 0
// #include <GxEPD2_BW.h> // including both doesn't use more code or ram
// #include <GxEPD2_3C.h> // including both doesn't use more code or ram
// #include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/U8g2_for_Adafruit_GFX-1.8.0/U8g2_for_Adafruit_GFX-1.8.0/src/U8g2_for_Adafruit_GFX.h"

// //if you have another microcontroller or another e-ink display module you have to change the following line
// // GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(D10, D9, D8, D7)); // GDEM029T94, Waveshare 2.9" V2 variant
// GxEPD2_BW<DISP, DISP::HEIGHT> display(DISP(D10, D9, D8, D7)); // BIEN CHOISIR L'ECRAN !!

// U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

// // void setup()
// // {
// //   display.init();
// //   display.setTextColor(NOIR);
// //   display.firstPage();

// // }


// // void loop() {

// // }
// // Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// // Requires HW SPI and Adafruit_GFX. Caution: the e-paper panels require 3.3V supply AND data lines!
// //
// // Display Library based on Demo Example from Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
// //
// // Author: Jean-Marc Zingg
// //
// // Version: see library.properties
// //
// // Library: https://github.com/ZinggJM/GxEPD2

// // Supporting Arduino Forum Topics:
// // Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// // Good Display ePaper for Arduino: https://forum.arduino.cc/index.php?topic=436411.0

// // see GxEPD2_wiring_examples.h for wiring suggestions and examples

// // base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code
// // enable or disable GxEPD2_GFX base class
// #define ENABLE_GxEPD2_GFX 0

// // uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
// //#include <GFX.h>
// // Note: if you use this with ENABLE_GxEPD2_GFX 1:
// //       uncomment it in GxEPD2_GFX.h too, or add #include <GFX.h> before any #include <GxEPD2_GFX.h>
// #include <GxEPD2_7C.h>
// #include <Fonts/FreeMonoBold9pt7b.h>

// // select the display constructor line in one of the following files (old style):


// // note 16.11.2019: the compiler may exclude code based on constant if statements (display.epd2.panel == constant),
// //                  therefore bitmaps may get optimized out by the linker

// // comment out unused bitmaps to reduce code space used

// #include "bitmaps/Bitmaps128x250.h" // 2.13" b/w


// // note for partial update window and setPartialWindow() method:
// // partial update window size and position is on byte boundary in physical x direction
// // the size is increased in setPartialWindow() if x or w are not multiple of 8 for even rotation, y or h for odd rotation
// // see also comment in GxEPD2_BW.h, GxEPD2_3C.h or GxEPD2_GFX.h for method setPartialWindow()

// const char HelloWorld[] = "Hello World!";
// const char HelloArduino[] = "Hello Arduino!";
// const char HelloEpaper[] = "Hello E-Paper!";

// void helloWorld()
// {
//   //Serial.println("helloWorld");
//   display.setRotation(3);
//   display.setFont(&FreeMonoBold9pt7b);
//   if (display.epd2.WIDTH < 104) display.setFont(0);
//   display.setTextColor(GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
//   // center bounding box by transposition of origin:
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() - tbh) / 2) - tby;
//   display.setFullWindow();
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print(HelloWorld);
//   }
//   while (display.nextPage());
//   //Serial.println("helloWorld done");
// }

// void helloWorldForDummies()
// {
//   const char text[] = "Hello World!";
//   display.setRotation(3);
//   // select a suitable font in Adafruit_GFX
//   display.setFont(&FreeMonoBold9pt7b);
//   // on e-papers black on white is more pleasant to read
//   display.setTextColor(GxEPD_BLACK);
//   // Adafruit_GFX has a handy method getTextBounds() to determine the boundary box for a text for the actual font
//   int16_t tbx, tby; uint16_t tbw, tbh; // boundary box window
//   display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh); // it works for origin 0, 0, fortunately (negative tby!)
//   // center bounding box by transposition of origin:
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() - tbh) / 2) - tby;
//   // full window mode is the initial mode, set it anyway
//   display.setFullWindow();
//   // here we use paged drawing, even if the processor has enough RAM for full buffer
//   // so this can be used with any supported processor board.
//   // the cost in code overhead and execution time penalty is marginal
//   // tell the graphics class to use paged drawing mode
//   display.firstPage();
//   do
//   {
//     // this part of code is executed multiple times, as many as needed,
//     // in case of full buffer it is executed once
//     // IMPORTANT: each iteration needs to draw the same, to avoid strange effects
//     // use a copy of values that might change, don't read e.g. from analog or pins in the loop!
//     display.fillScreen(GxEPD_WHITE); // set the background to white (fill the buffer with value for white)
//     display.setCursor(x, y); // set the postition to start printing text
//     display.print(text); // print some text
//     // end of part executed multiple times
//   }
//   // tell the graphics class to transfer the buffer content (page) to the controller buffer
//   // the graphics class will command the controller to refresh to the screen when the last page has been transferred
//   // returns true if more pages need be drawn and transferred
//   // returns false if the last page has been transferred and the screen refreshed for panels without fast partial update
//   // returns false for panels with fast partial update when the controller buffer has been written once more, to make the differential buffers equal
//   // (for full buffered with fast partial update the (full) buffer is just transferred again, and false returned)
//   while (display.nextPage());
//   //Serial.println("helloWorld done");
// }
#if false
void helloFullScreenPartialMode()
{
  //Serial.println("helloFullScreenPartialMode");
  const char fullscreen[] = "full screen update";
  const char fpm[] = "fast partial mode";
  const char spm[] = "slow partial mode";
  const char npm[] = "no partial mode";
  display.setPartialWindow(0, 0, display.width(), display.height());
  display.setRotation(3);
  display.setFont(&FreeMonoBold9pt7b);
  if (display.epd2.WIDTH < 104) display.setFont(0);
  display.setTextColor(GxEPD_BLACK);
  const char* updatemode;
  if (display.epd2.hasFastPartialUpdate)
  {
    updatemode = fpm;
  }
  else if (display.epd2.hasPartialUpdate)
  {
    updatemode = spm;
  }
  else
  {
    updatemode = npm;
  }
  // do this outside of the loop
  int16_t tbx, tby; uint16_t tbw, tbh;
  // center update text
  display.getTextBounds(fullscreen, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t utx = ((display.width() - tbw) / 2) - tbx;
  uint16_t uty = ((display.height() / 4) - tbh / 2) - tby;
  // center update mode
  display.getTextBounds(updatemode, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t umx = ((display.width() - tbw) / 2) - tbx;
  uint16_t umy = ((display.height() * 3 / 4) - tbh / 2) - tby;
  // center HelloWorld
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t hwx = ((display.width() - tbw) / 2) - tbx;
  uint16_t hwy = ((display.height() - tbh) / 2) - tby;
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(hwx, hwy);
    display.print(HelloWorld);
    display.setCursor(utx, uty);
    display.print(fullscreen);
    display.setCursor(umx, umy);
    display.print(updatemode);
  }
  while (display.nextPage());
  //Serial.println("helloFullScreenPartialMode done");
}
#endif
#if false
void helloArduino()
{
  //Serial.println("helloArduino");
  display.setRotation(3);
  display.setFont(&FreeMonoBold9pt7b);
  if (display.epd2.WIDTH < 104) display.setFont(0);
  display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  // align with centered HelloWorld
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  // height might be different
  display.getTextBounds(HelloArduino, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t y = ((display.height() / 4) - tbh / 2) - tby; // y is base line!
  // make the window big enough to cover (overwrite) descenders of previous text
  uint16_t wh = FreeMonoBold9pt7b.yAdvance;
  uint16_t wy = (display.height() / 4) - wh / 2;
  display.setPartialWindow(0, wy, display.width(), wh);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    //display.drawRect(x, y - tbh, tbw, tbh, GxEPD_BLACK);
    display.setCursor(x, y);
    display.print(HelloArduino);
  }
  while (display.nextPage());
  delay(1000);
  //Serial.println("helloArduino done");
}
#endif
// void helloEpaper()
// {
//   //Serial.println("helloEpaper");
//   display.setRotation(3);
//   display.setFont(&FreeMonoBold9pt7b);
//   if (display.epd2.WIDTH < 104) display.setFont(0);
//   display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   // align with centered HelloWorld
//   display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   // height might be different
//   display.getTextBounds(HelloEpaper, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t y = ((display.height() * 3 / 4) - tbh / 2) - tby; // y is base line!
//   // make the window big enough to cover (overwrite) descenders of previous text
//   uint16_t wh = FreeMonoBold9pt7b.yAdvance;
//   uint16_t wy = (display.height() * 3 / 4) - wh / 2;
//   display.setPartialWindow(0, wy, display.width(), wh);
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print(HelloEpaper);
//   }
//   while (display.nextPage());
//   //Serial.println("helloEpaper done");
// }

// // test partial window issue on GDEW0213Z19 and GDEH029Z13




// void helloValue(double v, int digits)
// {
//   //Serial.println("helloValue");
//   display.setRotation(3);
//   display.setFont(&FreeMonoBold9pt7b);
//   display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() * 3 / 4) - tbh / 2) - tby; // y is base line!
//   // show what happens, if we use the bounding box for partial window
//   uint16_t wx = (display.width() - tbw) / 2;
//   uint16_t wy = ((display.height() * 3 / 4) - tbh / 2);
//   display.setPartialWindow(wx, wy, tbw, tbh);
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print("bite");
//   }
//   while (display.nextPage());
//   delay(2000);
//   // make the partial window big enough to cover the previous text
//   uint16_t ww = tbw; // remember window width
//   display.getTextBounds(HelloEpaper, 0, 0, &tbx, &tby, &tbw, &tbh);
//   // adjust, because HelloEpaper was aligned, not centered (could calculate this to be precise)
//   ww = max(ww, uint16_t(tbw + 12)); // 12 seems ok
//   wx = (display.width() - tbw) / 2;
//   // make the window big enough to cover (overwrite) descenders of previous text
//   uint16_t wh = FreeMonoBold9pt7b.yAdvance;
//   wy = (display.height() * 3 / 4) - wh / 2;
//   display.setPartialWindow(wx, wy, ww, wh);
//   // alternately use the whole width for partial window
//   //display.setPartialWindow(0, wy, display.width(), wh);
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print("bite");
//   }
//   while (display.nextPage());
//   //Serial.println("helloValue done");
// }

// void deepSleepTest()
// {
//   //Serial.println("deepSleepTest");
//   const char hibernating[] = "hibernating ...";
//   const char wokeup[] = "woke up";
//   const char from[] = "from deep sleep";
//   const char again[] = "again";
//   display.setRotation(3);
//   display.setFont(&FreeMonoBold9pt7b);
//   if (display.epd2.WIDTH < 104) display.setFont(0);
//   display.setTextColor(GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   // center text
//   display.getTextBounds(hibernating, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() - tbh) / 2) - tby;
//   display.setFullWindow();
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print(hibernating);
//   }
//   while (display.nextPage());
//   display.hibernate();
//   delay(5000);
//   display.getTextBounds(wokeup, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t wx = (display.width() - tbw) / 2;
//   uint16_t wy = ((display.height() / 3) - tbh / 2) - tby; // y is base line!
//   display.getTextBounds(from, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t fx = (display.width() - tbw) / 2;
//   uint16_t fy = ((display.height() * 2 / 3) - tbh / 2) - tby; // y is base line!
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(wx, wy);
//     display.print(wokeup);
//     display.setCursor(fx, fy);
//     display.print(from);
//   }
//   while (display.nextPage());
//   delay(5000);
//   display.getTextBounds(hibernating, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t hx = (display.width() - tbw) / 2;
//   uint16_t hy = ((display.height() / 3) - tbh / 2) - tby; // y is base line!
//   display.getTextBounds(again, 0, 0, &tbx, &tby, &tbw, &tbh);
//   uint16_t ax = (display.width() - tbw) / 2;
//   uint16_t ay = ((display.height() * 2 / 3) - tbh / 2) - tby; // y is base line!
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(hx, hy);
//     display.print(hibernating);
//     display.setCursor(ax, ay);
//     display.print(again);
//   }
//   while (display.nextPage());
//   display.hibernate();
//   //Serial.println("deepSleepTest done");
// }

// void showBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool partial)
// {
//   //Serial.println("showBox");
//   display.setRotation(3);
//   if (partial)
//   {
//     display.setPartialWindow(x, y, w, h);
//   }
//   else
//   {
//     display.setFullWindow();
//   }
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.fillRect(x, y, w, h, GxEPD_BLACK);
//   }
//   while (display.nextPage());
//   //Serial.println("showBox done");
// }

// void drawCornerTest()
// {
//   display.setFullWindow();
//   display.setFont(&FreeMonoBold9pt7b);
//   display.setTextColor(GxEPD_BLACK);
//   for (uint16_t r = 0; r <= 4; r++)
//   {
//     display.setRotation(r);
//     display.firstPage();
//     do
//     {
//       display.fillScreen(GxEPD_WHITE);
//       display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
//       display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
//       display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
//       display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
//       display.setCursor(display.width() / 2, display.height() / 2);
//       display.print(display.getRotation());
//     }
//     while (display.nextPage());
//     delay(2000);
//   }
// }



// void drawFont(const char name[], const GFXfont* f)
// {
//   //display.setRotation(3);
//   display.fillScreen(GxEPD_WHITE);
//   display.setTextColor(GxEPD_BLACK);
//   display.setFont(f);
//   display.setCursor(0, 0);
//   display.println();
//   display.println(name);
//   display.println(" !\"#$%&'()*+,-./");
//   display.println("0123456789:;<=>?");
//   display.println("@ABCDEFGHIJKLMNO");
//   display.println("PQRSTUVWXYZ[\\]^_");
//   if (display.epd2.hasColor)
//   {
//     display.setTextColor(GxEPD_RED);
//   }
//   display.println("`abcdefghijklmno");
//   display.println("pqrstuvwxyz{|}~ ");
// }

// // note for partial update window and setPartialWindow() method:
// // partial update window size and position is on byte boundary in physical x direction
// // the size is increased in setPartialWindow() if x or w are not multiple of 8 for even rotation, y or h for odd rotation
// // see also comment in GxEPD2_BW.h, GxEPD2_3C.h or GxEPD2_GFX.h for method setPartialWindow()
// // showPartialUpdate() purposely uses values that are not multiples of 8 to test this

// void showPartialUpdate()
// {
//   // some useful background
//   helloWorld();
//   // use asymmetric values for test
//   uint16_t box_x = 10;
//   uint16_t box_y = 15;
//   uint16_t box_w = 70;
//   uint16_t box_h = 20;
//   uint16_t cursor_y = box_y + box_h - 6;
//   if (display.epd2.WIDTH < 104) cursor_y = box_y + 6;
//   float value = 13.95;
//   uint16_t incr = display.epd2.hasFastPartialUpdate ? 1 : 3;
//   display.setFont(&FreeMonoBold9pt7b);
//   if (display.epd2.WIDTH < 104) display.setFont(0);
//   display.setTextColor(GxEPD_BLACK);
//   // show where the update box is
//   for (uint16_t r = 0; r < 4; r++)
//   {
//     display.setRotation(r);
//     display.setPartialWindow(box_x, box_y, box_w, box_h);
//     display.firstPage();
//     do
//     {
//       display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
//       //display.fillScreen(GxEPD_BLACK);
//     }
//     while (display.nextPage());
//     delay(2000);
//     display.firstPage();
//     do
//     {
//       display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
//     }
//     while (display.nextPage());
//     delay(1000);
//   }
//   //return;
//   // show updates in the update box
//   for (uint16_t r = 0; r < 4; r++)
//   {
//     display.setRotation(r);
//     display.setPartialWindow(box_x, box_y, box_w, box_h);
//     for (uint16_t i = 1; i <= 10; i += incr)
//     {
//       display.firstPage();
//       do
//       {
//         display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
//         display.setCursor(box_x, cursor_y);
//         display.print(value * i, 2);
//       }
//       while (display.nextPage());
//       delay(500);
//     }
//     delay(1000);
//     display.firstPage();
//     do
//     {
//       display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
//     }
//     while (display.nextPage());
//     delay(1000);
//   }
// }


// void drawBitmaps()
// {
//   display.setFullWindow();
// }
// #ifdef _GxBitmaps128x250_H_
// void drawBitmaps128x250()
// {
// #if !defined(__AVR)
//   const unsigned char* bitmaps[] =
//   {
//     Bitmap128x250_1, logo128x250, first128x250, second128x250, third128x250
//   };
// #else
//   const unsigned char* bitmaps[] =
//   {
//     Bitmap128x250_1, logo128x250, first128x250, second128x250, third128x250
//   };
// #endif
//   if ((display.epd2.WIDTH == 128) && (display.epd2.HEIGHT == 250) && !display.epd2.hasColor)
//   {
//     bool m = display.mirror(true);
//     for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
//     {
//       display.firstPage();
//       do
//       {
//         display.fillScreen(GxEPD_WHITE);
//         display.drawInvertedBitmap(0, 0, bitmaps[i], 128, 250, GxEPD_BLACK);
//       }
//       while (display.nextPage());
//       delay(2000);
//     }
//     display.mirror(m);
//   }
// #ifdef _GxBitmaps128x250_H_
//  drawBitmaps128x250();
// #endif
// }
// #endif




// void draw7colors()
// {
//   display.setRotation(3);
//   uint16_t h = display.height() / 7;
//   display.firstPage();
//   do
//   {
//     display.fillRect(0, 0, display.width(), h, GxEPD_BLACK);
//     display.fillRect(0, h, display.width(), h, GxEPD_WHITE);
//     display.fillRect(0, 2 * h, display.width(), h, GxEPD_GREEN);
//     display.fillRect(0, 3 * h, display.width(), h, GxEPD_BLUE);
//     display.fillRect(0, 4 * h, display.width(), h, GxEPD_RED);
//     display.fillRect(0, 5 * h, display.width(), h, GxEPD_YELLOW);
//     display.fillRect(0, 6 * h, display.width(), h, GxEPD_ORANGE);
//   }
//   while (display.nextPage());
// }

// void draw7colorlines()
// {
//   display.setRotation(3);
//   uint16_t h = 2;
//   display.firstPage();
//   do
//   {
//     uint16_t y = 0;
//     do
//     {
//       display.fillRect(0, y, display.width(), h, GxEPD_BLACK); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_GREEN); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_BLUE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_RED); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_YELLOW); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_ORANGE); y += h;
//       display.fillRect(0, y, display.width(), h, GxEPD_WHITE); y += h;
//     }
//     while ((y + 12 * h) < uint16_t(display.height()));
//     //display.drawPixel(0, y, GxEPD_BLACK); display.drawPixel(10, y, GxEPD_GREEN);
//     //display.drawPixel(20, y, GxEPD_BLUE); display.drawPixel(30, y, GxEPD_RED);
//     //display.drawPixel(40, y, GxEPD_YELLOW); display.drawPixel(50, y, GxEPD_ORANGE);
//     display.fillRect(0, y, 2, 2, GxEPD_BLACK); display.fillRect(10, y, 2, 2, GxEPD_GREEN);
//     display.fillRect(20, y, 2, 2, GxEPD_BLUE); display.fillRect(30, y, 2, 2, GxEPD_RED);
//     display.fillRect(40, y, 2, 2, GxEPD_YELLOW); display.fillRect(50, y, 2, 2, GxEPD_ORANGE);
//   }
//   while (display.nextPage());
// }

// void setup()
// {
//   Serial.begin(115200);
//   Serial.println();
//   Serial.println("setup");
//   delay(100);
//   display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02
//   //display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
//   //display.init(115200, true, 10, false, SPI0, SPISettings(4000000, MSBFIRST, SPI_MODE0)); // extended init method with SPI channel and/or settings selection
//   // first update should be full refresh
//   helloWorld();
//   delay(1000);
//   // partial refresh mode can be used to full screen,
//   // effective if display panel hasFastPartialUpdate
//   helloFullScreenPartialMode();
//   delay(1000);
//   //stripeTest(); return; // GDEH029Z13 issue
//   helloArduino();
//   delay(1000);
//   helloEpaper();
//   delay(1000);
//   //helloValue(123.9, 1);
//   //delay(1000);
  
//   drawBitmaps();
// #if !defined(__AVR) // takes too long!
//   if (display.epd2.panel == GxEPD2::ACeP565)
//   {
//     //draw7colorlines();
//     //delay(2000);
//     draw7colors();
//     delay(4000);
//   }
// #endif
//   if (display.epd2.hasPartialUpdate)
//   {
//     showPartialUpdate();
//     delay(1000);
//   } // else // on GDEW0154Z04 only full update available, doesn't look nice
//   //drawCornerTest();
//   //showBox(16, 16, 48, 32, false);
//   //showBox(16, 56, 48, 32, true);
//   display.powerOff();
//   deepSleepTest();
//   Serial.println("setup done");
// }

// void loop()
// {
// }