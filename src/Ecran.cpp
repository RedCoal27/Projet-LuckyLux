#include "Ecran.h"

Ecran::Ecran(): m_Ecran(GxEPD2_213_B72(D10, D9, D8, D7)), m_nCurrentMenuIndex(0)
{
}

Ecran::~Ecran()
{
}

void Ecran::Initialiser()
{
    m_Ecran.init();
    m_Ecran.setFullWindow();
    m_Ecran.clearScreen();
    m_Ecran.setRotation(3);
    m_Ecran.firstPage();
}

void Ecran::AfficherBandeau()
{
    Batterie batterie;
    m_Ecran.setPartialWindow(0, 0, m_Ecran.width(), m_Ecran.height() - HAUTEUR_BANDEAU);
    m_Ecran.setTextColor(BLANC);
    m_Ecran.setTextColor(NOIR);

    do
    {
      m_Ecran.fillRect(0, 0, m_Ecran.width(),HAUTEUR_BANDEAU, NOIR);
    } 
    while (m_Ecran.nextPage());
    AfficherTexte("LuckyLux", 0, yMENU_MIN - 5 /*petite marge*/, BLANC);    
    AfficherBatterie(batterie.getVBat());
    }

void Ecran::AfficherRectangle(int x, int y, int w, int h, int couleur)
{
    m_Ecran.setPartialWindow(x, y, w, h);
    do
    {   
     m_Ecran.fillRect(x, y, w, h, couleur);
    }
    while(m_Ecran.nextPage());
}


void Ecran::AfficherTexteCentre(String str, int couleur)
{

    int16_t bordureTexteX, bordureTexteY; 
    uint16_t largeurTexte, hauteurTexte;

    m_Ecran.getTextBounds(str, 0, 0, &bordureTexteX, &bordureTexteY, &largeurTexte, &hauteurTexte);

    int16_t curX = ((m_Ecran.width() - largeurTexte)/2) - bordureTexteX;
    int16_t curY = ((m_Ecran.height() - hauteurTexte)/2) - bordureTexteY;
    m_Ecran.setTextColor(couleur);

    do
    {
        m_Ecran.setCursor(curX, curY);
        m_Ecran.print(str);        
    } 
    while (m_Ecran.nextPage());
    m_Ecran.setTextColor(NOIR);

}

void Ecran::AfficherTexte(String str, int x0, int y1, int couleur)
{
    // // int16_t bordureTexteX, bordureTexteY; 
    // // uint16_t largeurTexte, hauteurTexte;

    // // m_Ecran.getTextBounds(str, 0, 0, &bordureTexteX, &bordureTexteY, &largeurTexte, &hauteurTexte);
    // // int16_t curseurX = ((m_Ecran.width() - largeurTexte)/2) - bordureTexteX;
    // // int16_t curseurY = ((m_Ecran.height() - hauteurTexte)/2) - bordureTexteY;
    m_Ecran.setTextColor(couleur);
    do
    {
        m_Ecran.setCursor(x0, y1);
        m_Ecran.print(str);        
    } 
    while (m_Ecran.nextPage());
    m_Ecran.setTextColor(NOIR);

}

void Ecran::AfficherTexteMenu(String menu)
{   
    m_Ecran.setPartialWindow(xMENU_MIN, yMENU_MIN + 8, xMENU_MAX - xMENU_MIN, yMENU_MAX - yMENU_MIN);
    do
    {
        m_Ecran.setCursor(xMENU_MIN, yMENU_MIN);
        m_Ecran.fillRect(xMENU_MIN, yMENU_MIN, xMENU_MAX - xMENU_MIN, yMENU_MAX - yMENU_MIN, BLANC);
    } 
    while (m_Ecran.nextPage());
    AfficherTexteCentre(menu, NOIR);
}

void Ecran::setFont(const GFXfont* police)
{
    m_Ecran.setFont(police);
}

void Ecran::AfficherBatterie(const float pourcentage)
{
    do
    {
          //draw battery
        m_Ecran.fillRect(xMIN_BAT + WIDTH_BAT, yMIN_BAT + 2, 2, HEIGHT_BAT-4, BLANC);
        m_Ecran.drawRect(xMIN_BAT, yMIN_BAT, WIDTH_BAT, HEIGHT_BAT, BLANC);
        m_Ecran.fillRect(xMIN_BAT+1, yMIN_BAT+1, WIDTH_BAT-2, HEIGHT_BAT-2, NOIR);
        m_Ecran.fillRect(xMIN_BAT+1, yMIN_BAT+1, int(pourcentage * (WIDTH_BAT-2)), HEIGHT_BAT-2, BLANC);
      //m_Ecran.fillRect(xMIN_BAT, yMIN_BAT, 15, 6, BLANC);
    } 
    while (m_Ecran.nextPage());
}


int Ecran::getCurrentMenuIndex()
{
    return m_nCurrentMenuIndex;
}


void Ecran::setCurrentMenuIndex(int index)
{
    m_nCurrentMenuIndex = index;
}