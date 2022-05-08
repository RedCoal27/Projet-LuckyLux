#pragma once
#include <Arduino.h>
#include <Wire.h>
#define BOUTONA0 0
#define BOUTONA1 1
#define BOUTONA2 2


class Bouton{
private:
    bool* bLast;
    
public:
    Bouton();
    ~Bouton();
    bool pressed(int button);

};