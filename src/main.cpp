#include "color.h"
#include "LSD.h"
#include "Ecran.h"
#include "Bouton.h"


#define DISP GxEPD2_213_B72
#define _SD_PIN_CS 6


byte *gammatable = new byte[256];
Ecran _ECRAN; 
Bouton _BOUTON;
LSD _LSD;
tcs34725 _TCS;



void setup()
{
    _ECRAN.Initialiser();
    _LSD.setup(6);   
    _LSD.readfile(CSV); 
    delay(1000);
    _ECRAN.setFont(POLICE_BANDEAU);
    _ECRAN.AfficherBandeau();
    _ECRAN.setFont(POLICE_MENU);
    _ECRAN.menuEntree(LUMINANCE);
    _TCS.ColorSetup(gammatable);
    digitalWrite(LED_PWR, LOW); // turn off power LED
    digitalWrite(PIN_ENABLE_SENSORS_3V3, LOW); // turn sensor OFF

    pinMode(PIN_A6, OUTPUT);
    digitalWrite(PIN_A6, LOW);
}


void loop()
{
    delay(50);
    if(_BOUTON.pressed(BOUTONA0) == true)
    {
        //_ECRAN.menuSuivant();
        _LSD.SalleSuivante();
    }
    if(_BOUTON.pressed(BOUTONA1) == true)
    {
        //_ECRAN.menuPrecedant();
        _LSD.BatimentSuivant();
    }
    if(_BOUTON.pressed(BOUTONA2) == true)
    {   
        //R,G,B,Eclairement,Luminance
        int *colorInfo = new int[5];
        _TCS.ColorRead(gammatable, colorInfo);
        //_LSD.writeSalle("Salle 2", String(colorInfo[0]) + " " + String(colorInfo[1]) + " " + String(colorInfo[2])+";;");
        _ECRAN.AfficherTexteMenu(_LSD.getBatiment());
        delay(100);
        _ECRAN.AfficherTexteMenu(_LSD.getSalle());
        _LSD.write(DATA,colorInfo);
        _ECRAN.AfficherTexteMenu(String(colorInfo[0]) + " " + String(colorInfo[1]) + " " + String(colorInfo[2])+ " "+String(colorInfo[3]));
    }
}