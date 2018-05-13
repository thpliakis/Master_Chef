#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Competition.h"
#include "ExcursionAward.h"
#include "Team.h"

using namespace std;

class   CreativityCompetition : public Competition{
protected:
    ExcursionAward excersionAward;
    string *ingredients;

public:
    //constructors,destructor
    CreativityCompetition();
    CreativityCompetition(int id, string n, ExcursionAward e);
    ~CreativityCompetition();

    //setter
    void setExersionAward(ExcursionAward e);

    //getters
    ExcursionAward getExcursionAward();
    string* getIngredients();

    //other functions
    void status();
    void compete(Team &team1, Team &team2);

};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
