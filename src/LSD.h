#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <stdlib.h>
#include "list.h"

#define CSV "salle.csv"
#define DATA "data.bin"

class LSD{
private:
    List n_batiment;
    List n_salle;
    u_int16_t n_pbatiment;
    u_int16_t n_psalle;
public:
    LSD();
    ~LSD();
    void setup(int pinCS=10);
    void write(String nomFichier, int* Color);
    void readfile(String Salle);
    String readBatimentName(int Batiment);
};

