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
    void write(String nomFichier, String data);
    void readfile(String Salle);
    void readBatimentName(int Batiment);
};

