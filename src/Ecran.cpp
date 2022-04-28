#include "Ecran.h"
unsigned char _IMAGE[4000];

Ecran::Ecran():
    m_Paint(_IMAGE, EPD_WIDTH, EPD_HEIGHT),
    m_Ecran()
{
    // m_Ecran.Init(FULL);
    // m_Ecran.Display(_IMAGE);
}

Ecran::~Ecran()
{
}

void Ecran::Effacer()
{
    m_Paint.Clear(BLANC);
    
}

void Ecran::Initialiser()
{
    m_Paint.Clear(BLANC);
    m_Paint.SetRotate(ROTATE_90);
    m_Ecran.Init(FULL);
}

void Ecran::InitialiserPartiellement()
{
    m_Paint.Clear(BLANC);
    m_Paint.SetRotate(ROTATE_90);
    m_Ecran.Init(PART);
}

void Ecran::AfficherNom()
{
    m_Paint.DrawFilledRectangle(0, 114, 250, 128, RACISE);  //A SURCHARGER avec ligne()
    m_Paint.DrawStringAt(0, 112, "LuckyLux", &Font16, BLANC);   //A SURCHARGER avec ligne()
    m_Paint.DrawStringAt(151, 112, "Pre-alpha", &Font16, BLANC);    //A SURCHARGER avec ligne()
    m_Ecran.Display(_IMAGE);
}

void Ecran::AfficherMode()
{
    char* test = new char[20 * 20 / 8];
    Paint Paint_test(test, 20, 20);  
    m_Paint(test, EPD_WIDTH, EPD_HEIGHT),
    
}