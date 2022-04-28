#include "Ecran.h"

#define test_WIDTH 20
#define test_HEIGHT 20

unsigned char _IMAGE[4000];
unsigned char _imageTEST[50];

Ecran::Ecran():
    m_Paint(_IMAGE, EPD_WIDTH, EPD_HEIGHT),
    m_paintTest(_imageTEST, test_WIDTH, test_HEIGHT),
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
    
    m_Ecran.Display(_IMAGE);
}

void Ecran::Initialiser()
{
    m_Paint.Clear(BLANC);
    m_Paint.SetRotate(ROTATE_90);
    m_Ecran.Init(FULL);
}

void Ecran::InitialiserPartiellement()
{
    m_paintTest.Clear(BLANC);
    m_paintTest.SetRotate(ROTATE_90);
    m_Ecran.Init(PART);
}

void Ecran::AfficherNom()
{
    m_Paint.DrawFilledRectangle(0, 114, 250, 128, RACISE);  //A SURCHARGER avec ligne()
    m_Paint.DrawStringAt(0, 112, "LuckyLux", &Font16, BLANC);   //A SURCHARGER avec ligne()
    m_Paint.DrawStringAt(151, 112, "Pre-alpha", &Font16, BLANC);    //A SURCHARGER avec ligne()
    m_Ecran.DisplayPartBaseImage(_IMAGE);
    m_Paint.DrawLine(30, 30, 70, 70, RACISE);
    m_Ecran.DisplayPart(_IMAGE);
}

void Ecran::AfficherMode(const char* cpNomMode)
{  
    // m_paintTest.Clear(BLANC);
    // m_paintTest.DrawFilledRectangle(0, 0, test_WIDTH, test_HEIGHT, RACISE);
    
//    m_Ecran.DisplayPart(20, 50, _imageTEST, test_WIDTH, test_HEIGHT);
}