#pragma once
#include "GxEPD2.h"
#include "GxEPD2_BW.h"
#include "GxEPD2_EPD.h"
#include "GxEPD2_GFX.h"
#include <Arduino.h>
#include "bitmaps/Bitmaps128x250.h" // 2.13" b/w
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#include "LSD.h"
#include "epd/GxEPD2_213_B72.h"
#include "Batterie.h"

#define NOIR 0
#define BLANC 1
#define HAUTEUR_BANDEAU 16
#define xMIN 0
#define xMAX 250
#define yMIN 0
#define yMAX 128

//
#define xMENU_MIN xMIN
#define xMENU_MAX xMAX
#define yMENU_MIN HAUTEUR_BANDEAU
#define yMENU_MAX yMAX

//batterie paramètre 
#define xMIN_BAT 226
#define WIDTH_BAT 18
#define yMIN_BAT 3
#define HEIGHT_BAT 10

#define TROIS_MESURES 0
#define POLICE_MENU &FreeMonoBold12pt7b
#define POLICE_BANDEAU &FreeMono9pt7b



class Ecran
{
private:
    GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> m_Ecran;
    int m_nCurrentMenuIndex;
   
public:
    Ecran();
    ~Ecran();
    
    void Initialiser();
    void AfficherBandeau();
    void AfficherBatterie(const float pourcentage);
    void AfficherTexteCentre(String str, int couleur);
    void AfficherRectangle(int x, int y, int w, int h, int couleur);
    void AfficherTexte(String str, int x0, int y1, int couleur);
    void AfficherTexteMenu(String mode);
    void setFont(const GFXfont* police);

    void menuEntree(unsigned int indice);
    void menuSuivant();
    void menuPrecedant();
    int getCurrentMenuIndex();
    void setCurrentMenuIndex(int index);
};