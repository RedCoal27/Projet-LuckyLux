#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>




void SDsetup();
void SDwrite(String data);
void SDwriteBullshit(String data);