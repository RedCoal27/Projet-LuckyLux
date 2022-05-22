#include <Bouton.h>

Bouton::Bouton(){
    m_bLast = new bool[4];
    m_nTimer = new int[4];
    for(int i = 0; i < 4; i++){
        m_bLast[i] = digitalRead(i);
        m_nTimer[i] = 0;
    }
    pinMode(BOUTOND0, INPUT_PULLUP);
    pinMode(BOUTOND1, INPUT_PULLUP);
    pinMode(BOUTOND2, INPUT_PULLUP);
    pinMode(BOUTOND3, INPUT_PULLUP);
}

Bouton::~Bouton(){
    delete[] m_bLast;
}

bool Bouton::pressed(int button){
    bool state = digitalRead(button);
    if (m_bLast[button] != state && state == HIGH && m_nTimer[button] < TIMERDELAY){
        m_bLast[button] = state;
        return true;
    }
    m_bLast[button] = state;
    return false;
}


void Bouton::updateTimer(){
    for(int i = 0; i < 4; i++){
        if(m_bLast[i] == HIGH){
            m_nTimer[i]+=50;
        }
        else{
            m_nTimer[i] = 0;
        }
    }
}


bool Bouton::LongPressed(int button)
{
    if(m_nTimer[button] >= TIMERDELAY && m_nTimer[button] < TIMERDELAYMAX && digitalRead(button)==LOW){
        return true;
    }
    return false;
}