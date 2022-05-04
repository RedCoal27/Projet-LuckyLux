#include "Ecran.h"

Ecran::Ecran(const GFXfont* Police): m_Ecran(GxEPD2_213_B72(D10, D9, D8, D7)), m_Police(nullptr)
{
    if (Police != nullptr)
    {
        m_Police = new GFXfont(*Police);    
    }
     
}

Ecran::~Ecran()
{
}

void Ecran::Initialiser()
{
    m_Ecran.init();
    m_Ecran.setFullWindow();
    m_Ecran.clearScreen();
    m_Ecran.setFont(m_Police);
    m_Ecran.setRotation(3);
    m_Ecran.firstPage();
}


void Ecran::InitialiserPartiellement()
{
    Ecran::Initialiser();
    m_Ecran.setPartialWindow(0, 0, m_Ecran.width(), m_Ecran.height() - HAUTEUR_BANDEAU);
    m_Ecran.setTextColor(NOIR);
}
void Ecran::AfficherBandeau()
{
    m_Ecran.setPartialWindow(0, 0, m_Ecran.width(), m_Ecran.height() - HAUTEUR_BANDEAU);
    m_Ecran.firstPage();
    do
    {
      m_Ecran.fillRect(0, 0, m_Ecran.width(),HAUTEUR_BANDEAU, NOIR);
    } 
    while (m_Ecran.nextPage());
    AfficherTexte("LuckyLux",0, 0, m_Ecran.width(), HAUTEUR_BANDEAU - 4, BLANC);
    AfficherTexte("Alpha",0, 0, m_Ecran.width(), HAUTEUR_BANDEAU - 4, BLANC);
}

// // void Ecran::AfficherBandeau()
// // {
  
// //   // use asymmetric values for test
// //   uint16_t box_x = 10;
// //   uint16_t box_y = 15;
// //   uint16_t box_w = 70;
// //   uint16_t box_h = 20;
// //   uint16_t cursor_y = box_y + box_h - 6;
 

// //   // show where the update box is
 
// //     m_Ecran.setRotation(3);
// //     m_Ecran.setPartialWindow(box_x, box_y, box_w, box_h);
// //     m_Ecran.firstPage();
// //     do
// //     {
// //       m_Ecran.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
// //       //m_Ecran.fillScreen(GxEPD_BLACK);
// //     }
// //     while (m_Ecran.nextPage());
// //     delay(2000);
// //     m_Ecran.firstPage();
// //     do
// //     {
// //       m_Ecran.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
// //     }
// //     while (m_Ecran.nextPage());
// //     delay(1000);
// // }



void Ecran::AfficherTexteCentre(String str)
{
    m_Ecran.setPartialWindow(0, 0, m_Ecran.width(), m_Ecran.height() - HAUTEUR_BANDEAU);
    int16_t bordureTexteX, bordureTexteY; uint16_t largeurTexte, hauteurTexte;
    m_Ecran.getTextBounds(str, 0, 0, &bordureTexteX, &bordureTexteY, &largeurTexte, &hauteurTexte);
    int16_t curX = ((m_Ecran.width() - largeurTexte)/2) - bordureTexteX;
    int16_t curY = ((m_Ecran.height() - hauteurTexte)/2) - bordureTexteY;
    do
    {
        m_Ecran.fillScreen(BLANC);
        m_Ecran.setCursor(curX, curY);
        m_Ecran.print(str);        
    } 
    while (m_Ecran.nextPage());
}

void Ecran::AfficherTexte(String str, int x0, int y0, int x1, int y1, int couleur)
{

    m_Ecran.setPartialWindow(x0, y0, x1, y1);

    // // int16_t bordureTexteX, bordureTexteY; 
    // // uint16_t largeurTexte, hauteurTexte;

    // // m_Ecran.getTextBounds(str, 0, 0, &bordureTexteX, &bordureTexteY, &largeurTexte, &hauteurTexte);
    // // int16_t curseurX = ((m_Ecran.width() - largeurTexte)/2) - bordureTexteX;
    // // int16_t curseurY = ((m_Ecran.height() - hauteurTexte)/2) - bordureTexteY;
    do
    {
        m_Ecran.fillScreen(BLANC);
        m_Ecran.setCursor(x0, y0);
        m_Ecran.print(str);        
    } 
    while (m_Ecran.nextPage());
}
