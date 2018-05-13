#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Competition.h"
#include "ImmunityAward.h"
#include "Team.h"

using namespace std;

class   ImmunityCompetition : public Competition{
protected:
    ImmunityAward immunityAward;

public:
    //constructors,destructor
    ImmunityCompetition();
    ImmunityCompetition(int id, string n, ImmunityAward i);
    ~ImmunityCompetition();

    //setter
    void setImmunityAward(ImmunityAward a);
    //getter
    ImmunityAward getImmunityAward();

    //other functions
    void status();
    void compete(Team &team);

};
#endif // IMMUNITYCOMPETITION_H_INCLUDED
