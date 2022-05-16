#pragma once
#include <Arduino.h>
#include <Wire.h>
#define PIN_BATTERIE 14
#define TensionMax 3.3
#define BatterieVide 2.65
#define BatteriePleine 3

class Batterie{
private:
    float vBat;
public:
    Batterie();
    ~Batterie();
    float getVBat();
    void update();
    void calculVBat();
};
