#include "color.h"
#include "LSD.h"
#include "Ecran.h"
#include "Bouton.h"
#include "Batterie.h"

#define DISP GxEPD2_213_B72
#define _SD_PIN_CS 6


byte *gammatable = new byte[256];
Ecran _ECRAN; 
Bouton _BOUTON;
LSD _LSD;
tcs34725 _TCS;
Batterie _BATTERIE;
int *_colorInfo = new int[5];


void menuBatiment()
{
    _ECRAN.setCurrentMenuIndex(0);
    _ECRAN.AfficherTexteMenu(_LSD.getBatiment());

}

void menuSalle()
{
    
    _ECRAN.setCurrentMenuIndex(1);
    _ECRAN.AfficherTexteMenu(_LSD.getSalle());
    _ECRAN.setFont(&FreeMonoBold9pt7b);
    _ECRAN.AfficherTexte(_LSD.getBatiment(), xMENU_MIN, 119, NOIR);
    
}


void menuMesure(){
    _ECRAN.setCurrentMenuIndex(2);
    _ECRAN.setFont(&FreeMonoBold9pt7b);

    _ECRAN.AfficherTexte(_LSD.getSalle(), 0, 34, NOIR);
    _ECRAN.AfficherRectangle(0, 40, 250, 64, BLANC);
    
    _ECRAN.setFont(POLICE_MENU);
}


void getMesure(){
    //R,G,B,Eclairement,Luminance
    _TCS.ColorRead(gammatable, _colorInfo);
    _LSD.write(DATA,_colorInfo);
    _ECRAN.AfficherTexteCentre(String("R:") + String(_colorInfo[0]) + " V:" + String(_colorInfo[1]) + " B:" + String(_colorInfo[2])+ "L:" +String(_colorInfo[3]), NOIR);
}

void menuPrincipal()
{
    _ECRAN.Initialiser();
    _ECRAN.setFont(POLICE_BANDEAU);
    _ECRAN.AfficherBandeau();
    _ECRAN.setFont(POLICE_MENU);
    menuBatiment();
    
}

void setup()
{
    Serial.begin(9600);
    _LSD.setup(6);   
    _LSD.readfile(CSV); 
    menuPrincipal();
    _TCS.ColorSetup(gammatable);
    digitalWrite(LED_PWR, LOW); // turn off power LED
    digitalWrite(PIN_ENABLE_SENSORS_3V3, LOW); // turn sensor OFF

    pinMode(PIN_A6, OUTPUT);
    digitalWrite(PIN_A6, LOW);
    _ECRAN.AfficherBatterie(_BATTERIE.getVBat());
}


void loop()
{
    if  (_BOUTON.pressed(BOUTOND0))
    {
        if(_ECRAN.getCurrentMenuIndex() == 0)
        {
            _LSD.BatimentSuivant();
            _ECRAN.AfficherTexteMenu(_LSD.getBatiment());
        }
        else if(_ECRAN.getCurrentMenuIndex() == 1)
        {
            _LSD.SallePrecedente();
            _ECRAN.AfficherTexteMenu(_LSD.getSalle());
        }   
    }

    if  (_BOUTON.pressed(BOUTOND1))
    {
        if(_ECRAN.getCurrentMenuIndex() == 0)
        {
            _LSD.BatimentPrecedent();
            _ECRAN.AfficherTexteMenu(_LSD.getBatiment());
        }
        else if(_ECRAN.getCurrentMenuIndex() == 1)
        {
            _LSD.SalleSuivante();
            _ECRAN.AfficherTexteMenu(_LSD.getSalle());
        }
    }

    if  (_BOUTON.pressed(BOUTOND2))
    {
        if(_ECRAN.getCurrentMenuIndex() == 0)
        {
            menuSalle();

        }
        else if (_ECRAN.getCurrentMenuIndex() == 1)
        {
            menuMesure();
        }
        else if(_ECRAN.getCurrentMenuIndex() == 2)
        {
            getMesure();
        }   
    }


    if  (_BOUTON.LongPressed(BOUTOND1))
    {
        if(_ECRAN.getCurrentMenuIndex() == 1)
        {
            menuBatiment();
        }
        else if(_ECRAN.getCurrentMenuIndex() == 2)
        {
            menuSalle();
        }
    }
    
    _BOUTON.updateTimer();
    delay(50);
}
