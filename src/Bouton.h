#pragma once
#include <Arduino.h>
#include <Wire.h>
#define BOUTOND0 0
#define BOUTOND1 1
#define BOUTOND2 2
#define BOUTOND3 3


class Bouton{
private:
    bool* bLast;
public:
    Bouton();
    ~Bouton();
    bool pressed(int button);

};