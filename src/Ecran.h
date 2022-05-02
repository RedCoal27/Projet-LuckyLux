#pragma once
#include "GxEPD2.h"
#include "GxEPD2_BW.h"
#include "GxEPD2_EPD.h"
#include "GxEPD2_GFX.h"
#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/epd/GxEPD2_213_B72.h"
#include <Arduino.h>
#include "bitmaps/Bitmaps128x250.h" // 2.13" b/w
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/U8g2_for_Adafruit_GFX-1.8.0/U8g2_for_Adafruit_GFX-1.8.0/src/U8g2_for_Adafruit_GFX.h"
#include "LSD.h"
#define ENABLE_GxEPD2_GFX 0
#define NOIR 0
#define BLANC 1




class Ecran
{
private:
    GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> m_Ecran;
    GFXfont* m_Police;
public:
    Ecran(const GFXfont* Police = &FreeMonoBold9pt7b);
    ~Ecran();
    
    void Initialiser();
    void InitialiserPartiellement();
    void AfficherBandeau();
    void AfficherTexteCentre(String str);
    void AfficherTexteGauche(String str, int x0, int y0, int x1, int y1, int couleur);
    void AfficherTexteDroite(String str, int x0, int y0, int x1, int y1, int couleur);
};