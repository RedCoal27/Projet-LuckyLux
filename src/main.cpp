#include "color.h"
#include "LSD.h"
#include "Ecran.h"
#include "Bouton.h"
#define DISP GxEPD2_213_B72
#define _SD_PIN_CS 6


byte *gammatable = new byte[256];
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Ecran _ECRAN; 
Bouton _BOUTON;


void setup()
{
    _ECRAN.Initialiser();
    delay(1000);
    _ECRAN.setFont(POLICE_BANDEAU);
    _ECRAN.AfficherBandeau();
    _ECRAN.setFont(POLICE_MENU);
    _ECRAN.menuEntree(LUMINANCE);
    Serial.println("Setup");
    delay(5000);
}

void loop()
{
    if(_BOUTON.pressed(BOUTONA0) == true)
    {
        _ECRAN.menuSuivant();
    }
    if(_BOUTON.pressed(BOUTONA1) == true)
    {
        _ECRAN.menuPrecedant();
    }
    if(_BOUTON.pressed(BOUTONA2) == true)
    {
        _ECRAN.AfficherTexteMenu("test");
        int *colorInfo = new int[3];
        ColorRead(gammatable, &tcs, colorInfo);
        _ECRAN.AfficherTexteMenu(String(colorInfo[0]) + " " + String(colorInfo[1]) + " " + String(colorInfo[2]));
    }
// int *colorInfo = new int[3];
//   Serial.println("Reading color...");
//   delay(1000);
//   ColorRead(gammatable, &tcs, colorInfo);
//   Serial.println(String(colorInfo[0]) + ";" + String(colorInfo[1]) + ";" + String(colorInfo[2]) + ";\n");
//   delay(1000);
//   SDwrite("bite2.csv", String(colorInfo[0]) + ";" + String(colorInfo[1]) + ";" + String(colorInfo[2]) + ";\n");
}









// // // if you have another microcontroller or another e-ink display module you have to change the following line
// // GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(D10, D9, D8, D7)); // GDEM029T94, Waveshare 2.9" V2 variant
// GxEPD2_BW<DISP, DISP::HEIGHT> display(DISP(D10, D9, D8, D7)); // BIEN CHOISIR L'ECRAN !!


// void setup()
// {
//   display.init();
//   display.setTextColor(NOIR);
//   display.firstPage();

// }


// void loop() {

// }




// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: the e-paper panels require 3.3V supply AND data lines!

// Display Library based on Demo Example from Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html

// Author: Jean-Marc Zingg

// Version: see library.properties

// Library: https://github.com/ZinggJM/GxEPD2

// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Display ePaper for Arduino: https://forum.arduino.cc/index.php?topic=436411.0

// see GxEPD2_wiring_examples.h for wiring suggestions and examples

// base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code
// enable or disable GxEPD2_GFX base class

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
// #include <GFX.h>
// Note: if you use this with ENABLE_GxEPD2_GFX 1:
//       uncomment it in GxEPD2_GFX.h too, or add #include <GFX.h> before any #include <GxEPD2_GFX.h>


// select the display constructor line in one of the following files (old style):


// note 16.11.2019: the compiler may exclude code based on constant if statements (display.epd2.panel == constant),
//                  therefore bitmaps may get optimized out by the linker

// comment out unused bitmaps to reduce code space used



// note for partial update window and setPartialWindow() method:
// partial update window size and position is on byte boundary in physical x direction
// the size is increased in setPartialWindow() if x or w are not multiple of 8 for even rotation, y or h for odd rotation
// see also comment in GxEPD2_BW.h, GxEPD2_3C.h or GxEPD2_GFX.h for method setPartialWindow()



/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


// void setup()
// {// helloWorld();
//   // delay(1000);
//   // // partial refresh mode can be used to full screen,
//   // // effective if display panel hasFastPartialUpdate
//   // helloFullScreenPartialMode();
//   // delay(1000);
//   // helloArduino();
//   // delay(1000);
//   // helloEpaper();
//   // delay(1000);
//   // display.powerOff();
//   // deepSleepTest();
//   // display.nextPage();
// }

// void loop()
// {
// }