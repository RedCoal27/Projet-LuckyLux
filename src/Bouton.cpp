#include <Bouton.h>

Bouton::Bouton(){
    bLast = new bool[4];
    for(int i = 0; i < 4; i++){
        bLast[i] = digitalRead(i);
    }
    pinMode(0, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
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