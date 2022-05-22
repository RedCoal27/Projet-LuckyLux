#pragma once
#include <Arduino.h>
#include <Wire.h>
#define BOUTOND0 0
#define BOUTOND1 1
#define BOUTOND2 2
#define BOUTOND3 3

#define TIMERDELAY 1000
#define TIMERDELAYMAX 2000

#define MAINDELAY 50

class Bouton{
private:
    bool* bLast;
    int* n_Timer;
public:
    Bouton();
    ~Bouton();
    bool pressed(int button);
    void updateTimer();
    bool LongPressed(int button);
};