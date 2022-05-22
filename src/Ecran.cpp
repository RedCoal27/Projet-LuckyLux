#include "Ecran.h"

Ecran::Ecran(): m_Ecran(GxEPD2_213_B72(D10, D9, D8, D7)), m_spMenu(nullptr), m_nCompteurMenu(0), m_Batterie()
{
    m_spMenu = new String[5] {"Trois Mesures", "Eclairement", "Couleur",  "Luminance", "Mesure Continue"};
}

Ecran::~Ecran()
{
    delete[] m_spMenu;
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
    m_Ecran.setPartialWindow(0, 0, m_Ecran.width(), m_Ecran.height() - HAUTEUR_BANDEAU);

    int16_t bordureTexteX, bordureTexteY; 
    uint16_t largeurTexte, hauteurTexte;
    String sValBatterie = String(m_Batterie.getVBat());
    m_Ecran.setTextColor(BLANC);
    m_Ecran.setTextColor(NOIR);

    do
    {
      m_Ecran.fillRect(0, 0, m_Ecran.width(),HAUTEUR_BANDEAU, NOIR);
    } 
    while (m_Ecran.nextPage());
    m_Ecran.getTextBounds(sValBatterie, 0, 0, &bordureTexteX, &bordureTexteY, &largeurTexte, &hauteurTexte);
    AfficherTexte("LuckyLux", 0, yMENU_MIN - 5 /*petite marge*/, BLANC);
    AfficherTexte(sValBatterie, xMAX - largeurTexte - 1, yMENU_MIN - 5, BLANC);
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

void Ecran::AfficherTexteMenu(String mode)
{   
    m_Ecran.setPartialWindow(xMENU_MIN, yMENU_MIN + 8, xMENU_MAX - xMENU_MIN, yMENU_MAX - yMENU_MIN);
    do
    {
        m_Ecran.setCursor(xMENU_MIN, yMENU_MIN);
        m_Ecran.fillRect(xMENU_MIN, yMENU_MIN, xMENU_MAX - xMENU_MIN, yMENU_MAX - yMENU_MIN, BLANC);
    } 
    while (m_Ecran.nextPage());
    AfficherTexteCentre(mode, NOIR);
}

void Ecran::setFont(const GFXfont* police)
{
    m_Ecran.setFont(police);
}
void Ecran::menuEntree(unsigned int indice)
{
    AfficherTexteMenu(m_spMenu[indice]);
    if (indice < 5)
        m_nCompteurMenu = indice;
    else
        m_nCompteurMenu = 0;
}

void Ecran::menuSuivant()
{
    m_nCompteurMenu++;
    if (m_nCompteurMenu >= 5)
        m_nCompteurMenu = 0; 
    AfficherTexteMenu(m_spMenu[m_nCompteurMenu]);
}

void Ecran::menuPrecedant()
{
    m_nCompteurMenu--;
    if (m_nCompteurMenu < 0)
        m_nCompteurMenu = 4; 
    AfficherTexteMenu(m_spMenu[m_nCompteurMenu]);
}