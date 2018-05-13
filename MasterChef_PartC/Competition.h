#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


class Competition{

protected:
    int id;
    string name;
    string winner;

public:
    Competition();
    Competition(int i, string n);
    ~Competition();

    //setters
    void setId(int i);
    void setName(string n);
    void setWinner(string w);

    //getters
    int getId();
    string getName();
    string getWinner();

    //other functions
    void status();

};






#endif // COMPETITION_H_INCLUDED
