#include <Bouton.h>

Bouton::Bouton(){
    m_bLast = new bool[3];
    m_nTimer = new int[3];
    pinMode(BOUTOND0, INPUT_PULLUP);
    pinMode(BOUTOND1, INPUT_PULLUP);
    pinMode(BOUTOND2, INPUT_PULLUP);
    for(int i = 0; i < 3; i++){
        m_bLast[i] = digitalRead(i);
        m_nTimer[i] = 0;
    }
    // pinMode(BOUTOND3, INPUT_PULLUP);
}

Bouton::~Bouton(){
    delete[] m_bLast;
    delete[] m_nTimer;
}

bool Bouton::pressed(int button)
{
    bool state = digitalRead(button);
    if (m_bLast[button] != state && state == HIGH && m_nTimer[button] < TIMERDELAY){
        m_bLast[button] = state;
        return true;
    }
    m_bLast[button] = state;
    return false;
}


void Bouton::updateTimer(){
    for(int i = 0; i < 3; i++){
        if(digitalRead(i) == LOW){
            m_nTimer[i]+=MAINDELAY;
            Serial.println("Bouton " + String(i) + " : " + String(m_nTimer[i]));
        }
        else{
            m_nTimer[i] = 0;
        }
    }
}


bool Bouton::LongPressed(int button)
{
    // if(m_nTimer[button] >= TIMERDELAY && m_nTimer[button] < TIMERDELAYMAX && digitalRead(button)==HIGH)
    // {
    //     return true;
    // }
    if(m_nTimer[button] >= TIMERDELAY && digitalRead(button)==HIGH && m_nTimer[button]<=TIMERDELAYMAX)
    {
        return true;
    }
    return false;
}