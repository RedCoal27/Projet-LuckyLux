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

Ecran _ECRAN;

void setup()
{
  _ECRAN.Initialiser();
  _ECRAN.Effacer();
  _ECRAN.InitialiserPartiellement();
  _ECRAN.AfficherNom();
}

void loop()
{
 
}





