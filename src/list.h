#pragma once

//classe list
class List
{
private:
    int n_element;
    int* n_tab;
public:
    List();
    ~List();
    List(const List&);
    List operator+= (int);
    int operator[] (int);
    List operator= (List);
    int size();
};