#include <button.h>

Button::Button(){
    last = new bool[3];
    for(int i = 0; i < 3; i++){
        last[i] = digitalRead(i);
    }
    pinMode(0, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
}

Button::~Button(){
    delete[] last;
}

bool Button::pressed(int button){
    bool state = digitalRead(button);
    if (last[button] != state && state == LOW){
        last[button] = state;
        Serial.println("Pressed "+String(button));
        return true;
    }
    last[button] = state;
    return false;
}