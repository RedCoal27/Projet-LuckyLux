#include <Bouton.h>

Bouton::Bouton(){
    bLast = new bool[4];
    n_Timer = new int[4];
    for(int i = 0; i < 4; i++){
        bLast[i] = digitalRead(i);
        n_Timer[i] = 0;
    }
    pinMode(BOUTOND0, INPUT_PULLUP);
    pinMode(BOUTOND1, INPUT_PULLUP);
    pinMode(BOUTOND2, INPUT_PULLUP);
    pinMode(BOUTOND3, INPUT_PULLUP);
}

Bouton::~Bouton(){
    delete[] bLast;
}

bool Bouton::pressed(int button){
    bool state = digitalRead(button);
    if (bLast[button] != state && state == LOW){
        bLast[button] = state;
        return true;
    }
    bLast[button] = state;
    return false;
}


void Bouton::updateTimer(){
    for(int i = 0; i < 4; i++){
        if(bLast[i] == HIGH){
            n_Timer[i]+=50;
        }
        else{
            n_Timer[i] = 0;
        }
    }
}


bool Bouton::LongPressed(int button){
    if(n_Timer[button] > TIMERDELAY && n_Timer[button] < TIMERDELAYMAX && digitalRead(button)==LOW){
        return true;
    }
    return false;
}