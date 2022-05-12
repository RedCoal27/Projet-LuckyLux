#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>



class LSD{
public:
    LSD();
    ~LSD();
    void setup(int pinCS=10);
    void write(String nomFichier, String data);
    void read(String nomFichier, String* data);
    void writeSalle(String Salle, String data);
    void readSalle(String Salle);
};

