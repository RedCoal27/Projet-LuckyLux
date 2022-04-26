#pragma once
#include "epd2in13_V2.h"
#include "epdpaint.h"
#include "imagedata.h"
#define RACISE 0
#define BLANC 1



class Ecran
{
private:
    Paint m_Paint;
    Epd m_Ecran;
    
public:
    Ecran();
    ~Ecran();

    void Initialiser();
    void Effacer();
    void AfficherNom();//bite
 
    //void Ligne();
};