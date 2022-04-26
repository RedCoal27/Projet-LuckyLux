#include "Ecran.h"
unsigned char _bgIMAGE[4000];
unsigned char _fgIMAGE[4000];

Ecran::Ecran():
    m_fgPaint(_fgIMAGE, EPD_WIDTH, EPD_HEIGHT),
    m_bgPaint(_bgIMAGE, EPD_WIDTH, EPD_HEIGHT),
    m_Ecran()
{

}

Ecran::~Ecran()
{
}

void Ecran::Effacer()
{
    m_Ecran.Clear();
}

void Ecran::Initialiser()
{
    m_Ecran.Init(PART);
    m_Ecran.Clear();

    m_fgPaint.SetRotate(ROTATE_90);
    m_bgPaint.SetRotate(ROTATE_90);
}

void Ecran::AfficherNom()
{
    m_bgPaint.DrawFilledRectangle(0, 114, 250, 128, RACISE);  //A SURCHARGER avec ligne()
    m_bgPaint.DrawStringAt(0, 112, "LuckyLux", &Font16, BLANC);   //A SURCHARGER avec ligne()
    m_bgPaint.DrawStringAt(151, 112, "Pre-alpha", &Font16, BLANC);    //A SURCHARGER avec ligne()
    m_fgPaint.DrawStringAt(50, 50, "Bite", &Font16, BLANC);
    m_Ecran.DisplayPartBaseImage(_bgIMAGE);
    m_Ecran.DisplayPart(_fgIMAGE);
}