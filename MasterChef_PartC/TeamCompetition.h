#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

/*#include <stdlib.h>
#include <iostream>
#include <string>*/
#include "Competition.h"
#include "Round.h"
#include "FoodAward.h"
#include "Team.h"

using namespace std;



class TeamCompetition : public Competition{

    Round *rounds;
    FoodAward foodAward;

public:
    //constructors,destructor
    TeamCompetition();
    TeamCompetition(int id, string n, FoodAward fa);
    ~TeamCompetition();

    //setters
    void setFoodAward(FoodAward fa);

    //getters
    Round* getRounds();
    FoodAward getFoodAward();

    //other functions
    void status();
    int compete(Team &team1, Team &team2);
};

#endif // TEAMCOMPETITION_H_INCLUDED
