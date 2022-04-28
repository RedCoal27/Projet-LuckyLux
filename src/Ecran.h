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
    void InitialiserPartiellement();
    void Effacer();
    void AfficherNom();
    void AfficherMode(const char*);
    //void Ligne();
};