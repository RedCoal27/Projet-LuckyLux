#include "Batterie.h"


Batterie::Batterie(){
//    vBat = analogRead(PIN_BATTERIE);
//    calculVBat();
}


Batterie::~Batterie(){

}


float Batterie::getVBat(){
    calculVBat();
    return vBat;
}


void Batterie::update(){
    vBat = analogRead(PIN_BATTERIE);
}




void Batterie::calculVBat(){
    vBat = analogRead(PIN_BATTERIE);
    // Serial.println(vBat);
    vBat = vBat/1023*TensionMax;
    //tension batterie entre BatterieVide et BatteriePleine EN %
    vBat = (vBat - BatterieVide)/(BatteriePleine - BatterieVide)*100;
    if (vBat < 0) vBat = 0;
    if (vBat > 100) vBat = 100;
}