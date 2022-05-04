#pragma once
#include "GxEPD2.h"
#include "GxEPD2_BW.h"
#include "GxEPD2_EPD.h"
#include "GxEPD2_GFX.h"
#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/GxEPD2/src/epd/GxEPD2_213_B72.h"
#include <Arduino.h>
#include "bitmaps/Bitmaps128x250.h" // 2.13" b/w
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "/home/mouss/Documents/Projet-LuckyLux/.pio/libdeps/nano33ble/U8g2_for_Adafruit_GFX-1.8.0/U8g2_for_Adafruit_GFX-1.8.0/src/U8g2_for_Adafruit_GFX.h"
#include "LSD.h"
#define NOIR 0
#define BLANC 1
#define HAUTEUR_BANDEAU 16
#define xMIN 0
#define xMAX 250
#define yMIN 0
#define yMAX 128
#define xMENU_MIN xMIN
#define xMENU_MAX xMAX
#define yMENU_MIN HAUTEUR_BANDEAU
#define yMENU_MAX yMAX




class Ecran
{
private:
    GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> m_Ecran;
public:
    Ecran();
    ~Ecran();
    
    void Initialiser();
    void AfficherBandeau();
    void AfficherTexteCentre(String str, int couleur);
    void AfficherTexte(String str, int x0, int y1, int couleur);
    void AfficherTexteMenu(String mode);
    void setFont(const GFXfont* police);
};