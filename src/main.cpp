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
#include "epdpaint.h"
// #include "imagedata.h"
// #include "Ecran.h"
// #include <string>

#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/epd/GxEPD2_213.h"
GxEPD2_213 _ECRAN(D10, D9, D8, D7);
u_int8_t _BMP[(250*128)/8];
Paint paintTest(_BMP, 122, 250);
void setup()
{
paintTest.DrawFilledCircle(10, 10, 5, 0);
    
  _ECRAN.clearScreen();
  _ECRAN.writeScreenBuffer();
  _ECRAN.drawImage(_BMP, 0, 0, 250, 122);
}

void loop()
{

}

// Ecran _ECRAN;

// void setup()
// {
//   _ECRAN.Initialiser();
//   _ECRAN.Effacer();
//   // _ECRAN.InitialiserPartiellement();
//   // _ECRAN.AfficherNom();
// }

// void loop()
// {
 
// }





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

