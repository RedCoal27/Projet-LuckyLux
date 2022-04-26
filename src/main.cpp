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



#include <Arduino.h>
#include <SPI.h>
#include "epd2in13_V2.h"
#include "epdpaint.h"
#include "imagedata.h"
#include "Ecran.h"
#include <string>


Ecran _ECRAN;

void setup()
{
  _ECRAN.Initialiser();
  _ECRAN.AfficherNom();
  _ECRAN.AfficherMode("Luminance");
}

void loop()
{
 
}





// #include <Arduino.h>

// void setup()
// {
//     pinMode(13, OUTPUT);
// }

// void loop()
// {
//     digitalWrite(13, HIGH);
//     delay(500);
//     digitalWrite(13, LOW);
//     delay(500);
//     delay(500);
//     delay(500);
// }

