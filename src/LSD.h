#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>




void SDsetup(int pinCS = 10);
void SDwrite(String nomFichier, String data);
void SDread(String nomFichier, String* data);