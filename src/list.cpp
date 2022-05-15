#include "list.h"
#include <Arduino.h>

List::List():n_element(0),n_tab(nullptr){
}


List::~List(){
    delete[] n_tab;
}


List::List(const List& l){
    n_element = l.n_element;
    n_tab = new int[n_element];
    for(int i=0;i<n_element;i++){
        n_tab[i] = l.n_tab[i];
    }
}


List List::operator+= (int n){
    int* tmp = new int[n_element+1];
    for(int i=0;i<n_element;i++){
        tmp[i] = n_tab[i];
    }
    tmp[n_element] = n;
    if(n_tab != nullptr){
        delete[] n_tab;
    }
    n_tab = tmp;
    n_element++;
    return *this;
}


int List::operator[] (int n){
    return n_tab[n];
}


List List::operator=(List l){
    n_element = l.n_element;
    n_tab = new int[n_element];
    for(int i=0;i<n_element;i++){
        n_tab[i] = l.n_tab[i];
    }
    return *this;
}


int List::size(){
    return n_element;
}