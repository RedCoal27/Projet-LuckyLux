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
    m_Ecran.Init(FULL);
    m_Ecran.Clear();
    m_fgPaint.Clear(BLANC);
    m_fgPaint.SetRotate(ROTATE_90);
    m_bgPaint.SetRotate(ROTATE_90);
    
}

void Ecran::AfficherNom()
{
    m_bgPaint.DrawFilledRectangle(10, 10, 50, 50, RACISE);  //A SURCHARGER avec ligne()
    m_bgPaint.DrawStringAt(0, 112, "LuckyLux", &Font16, BLANC);   //A SURCHARGER avec ligne()
    m_bgPaint.DrawStringAt(151, 112, "Pre-alpha", &Font16, BLANC);    //A SURCHARGER avec ligne()
    m_Ecran.Display(_bgIMAGE);
}