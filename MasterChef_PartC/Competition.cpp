#include <stdlib.h>
#include <iostream>
#include <string>

#include "Competition.h"

using namespace std;


Competition::Competition(){
    id = 0;
    name = "";
    winner = "";
}

Competition::Competition(int i, string n){
    id = i;
    name = n;
}

Competition::~Competition(){
        //cout << "Destroyed!"<< endl;
}

//setters
void Competition::setId(int i)
{
    id =i;
}

void Competition::setName(string n)
{
    name=n;
}

void Competition::setWinner(string w)
{
    winner=w;
}


//getters
int Competition::getId()
{
    return id;
}

string Competition::getName()
{
    return name;
}

string Competition::getWinner()
{
    return winner;
}


//other functions
void Competition::status()
{
    cout <<"id: "<<id<<"\nname: "<<name<<"\nwinner: "<<winner<<endl;
}


