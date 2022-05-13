#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "list.h"

#define CSV "salle.csv"
#define DATA "data.bin"

class LSD{
private:
    List n_batiment;
    List n_salle;
public:
    LSD();
    ~LSD();
    void setup(int pinCS=10);
    void write(String nomFichier, u_int16_t Batiment,u_int16_t Salle, int* Color,  u_int16_t Eclairement, u_int16_t Luminance);
    void readfile(String Salle);
    String readBatimentName(int Batiment);
};

