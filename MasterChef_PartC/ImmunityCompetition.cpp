#include <stdlib.h>
#include <iostream>
#include <string>
#include "ImmunityCompetition.h"

using namespace std;

//constructors,destructor
ImmunityCompetition::ImmunityCompetition(){

}

ImmunityCompetition::ImmunityCompetition(int id, string n,ImmunityAward i) : Competition(id, n){
    immunityAward=i;
}

ImmunityCompetition::~ImmunityCompetition(){
    //cout << "Destroyed!"<< endl;
}

//setter
void ImmunityCompetition::setImmunityAward(ImmunityAward a){
    immunityAward=a;
}

//getter
ImmunityAward ImmunityCompetition::getImmunityAward(){
    return immunityAward;
}

//other functions
void ImmunityCompetition::status(){
    immunityAward.status();
}

void ImmunityCompetition::compete(Team &team){

    //Δήλωση πινάκα για τοπική αποθήκευση των παικτών της ομάδας.
    Player *player;
    player = new Player[team.getNumberOfPlayers()];

    //Δήλωση καλύτερου συνδιασμού.
    float maxCombination=-1;
    //Δήλωση θέσης παίκτη με τον καλύτερο συνδιασμό.
    int maxInddex=-1;

    //Δήλωση συνδιασμού.
    float combination=-1;

    //Έυρεση παίκτη με τον καλύτερο συνδιασμό.
    for(int playerIndex = 0; playerIndex<(team.getNumberOfPlayers()); playerIndex++){
        combination = (0.75*player[playerIndex].getTechnique() + 0.25*(100-player[playerIndex].getFatigue()));
        if (maxCombination < combination){
            maxCombination = combination;
            maxInddex = playerIndex;
        }
    }

    //Αύξηση νικών παίκτη.
    player[maxInddex].setWins(player[maxInddex].getWins() + 1);


}

