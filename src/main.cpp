// #include "color.h"

// #include "LSD.h"
// #include <iostream>
// #include "EPaper.h"

// byte *gammatable = new byte[256];
// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// int *colorInfo = new int[3];

// // void setup()
// // {
// //   delay(2000);
// //   // ColorSetup(gammatable, &tcs);
// //   // SDsetup();
// // }


// // void loop()
// // {
// //   delay(100);
// //   // ColorRead(gammatable, &tcs, colorInfo);
// //   // SDwrite(String(colorInfo[0]) + ";" + String(colorInfo[1]) + ";" + String(colorInfo[2]) + ";\n");
// //   // SDwriteBullshit(String("bullshit ; ; ;"));

// // }



// #include <Arduino.h>
// #include <SPI.h>
// #include "epd2in13_V2.h"
// #include "epdpaint.h"
// #include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/bitmaps/Bitmaps128x250.h"
#include "imagedata.h"
#include "Ecran.h"
#include <string>

// #include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/epd/GxEPD2_213.h"
// GxEPD2_213 _ECRAN(D10, D9, D8, D7);
// u_int8_t _BMP[(250*128)/8];
// Paint paintTest(_BMP, 122, 250);

// void setup()
// {

//   _ECRAN.init();
//   // comment out next line to have no or minimal Adafruit_GFX code
//   _ECRAN.setTextColor(GxEPD_BLACK);
//   _ECRAN.firstPage();
//   do
//   {
//     _ECRAN.fillScreen(GxEPD_WHITE);
//     // comment out next line to have no or minimal Adafruit_GFX code
//     _ECRAN.print("Hello World!");
//   }
//   while (_ECRAN.nextPage());
// }

// void loop()
// {

// }

// Ecran _ECRAN;

// void setup()
// {
//   _ECRAN.Initialiser();
//   delay(2000);
//   // _ECRAN.InitialiserPartiellement();
//   // _ECRAN.AfficherNom();
// }

// void loop()
// {
 
// }





#define ENABLE_GxEPD2_GFX 0
#define BLANC 1
#define NOIR 0
#include <GxEPD2_BW.h> // including both doesn't use more code or ram
#include <GxEPD2_3C.h> // including both doesn't use more code or ram
#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/U8g2_for_Adafruit_GFX-1.8.0/U8g2_for_Adafruit_GFX-1.8.0/src/U8g2_for_Adafruit_GFX.h"

//if you have another microcontroller or another e-ink display module you have to change the following line
// GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(D10, D9, D8, D7)); // GDEM029T94, Waveshare 2.9" V2 variant
GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> display(GxEPD2_213_B72(D10, D9, D8, D7)); // GDEM029T94, Waveshare 2.9" V2 variant

U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

// void setup()
// {
//   display.init();
//   display.setTextColor(NOIR);
//   display.firstPage();
//   display.setRotation(1);

//   u8g2Fonts.begin(display); // connect u8g2 procedures to Adafruit GFX


//   uint16_t bg = BLANC;
//   uint16_t fg = NOIR;
//   u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
//   u8g2Fonts.setBackgroundColor(bg);

//     display.fillScreen(BLANC);

//     u8g2Fonts.setFont(u8g2_font_fub14_tr);   //font is set
//     u8g2Fonts.setCursor(10, 10);             //cursor(x,y)
//     u8g2Fonts.print("Millis: ");   //print the text
 
// }


// void loop() {
//   display.setPartialWindow(0, 0, 250, 128);
//   display.firstPage();

//   do{
//     display.fillScreen(BLANC);
//     u8g2Fonts.setCursor(0, 0);
//     u8g2Fonts.print(millis());
//   }while(display.nextPage());
// }
void setup()
{
  display.init();
  display.setFullWindow();
  display.clearScreen();
}

void loop()
{

}