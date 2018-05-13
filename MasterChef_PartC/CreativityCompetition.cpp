#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

#include "CreativityCompetition.h"
#include "Player.h"



using namespace std;

//constructors,destructor
CreativityCompetition::CreativityCompetition(){

    ingredients=new string[10];
}

CreativityCompetition::CreativityCompetition(int id, string n, ExcursionAward e) : Competition(id, n){

    excersionAward = e;
    ingredients = new string[10] {"patates","ntomates","kremidia","kotopoylo","kimas","ladi","alati","piperi","rigani","thymari"};
}

CreativityCompetition::~CreativityCompetition(){
    delete [] ingredients;
    //cout << "Destroyed!"<< endl;
}

//setter
void CreativityCompetition::setExersionAward(ExcursionAward e){
    excersionAward=e;
}

//getters
ExcursionAward CreativityCompetition::getExcursionAward(){
    return excersionAward;
 }

string* CreativityCompetition::getIngredients(){
    return ingredients;
 }


//other functions
void CreativityCompetition::status(){
    //cout << id <<endl;
    //cout << name <<endl;
    //cout << winner <<endl;

    excersionAward.status();
    for(int k=0;k<10;k++)
    {
        cout << "Ingredient "<< k <<" : "<< ingredients[k]<<endl;
    }
}

 void CreativityCompetition::compete(Team &team1, Team &team2){
    //Δήλωση 2 πινάκων για τοπική αποθήκευση παικτών κάθε ομάδας, ο player θα είναι ο ενιαίος πίνακας παικτών.
    Player *player;
    player = new Player[team1.getNumberOfPlayers() + team2.getNumberOfPlayers()];


    //Τοπική αποθήκευση παικτών 1ης ομάδας.
    player=team1.getPlayers();


    //Δήλωση μέγιστης τεχνικής κατάρτισης.
    float maxTechnique=-1;
    //Δήλωση θέσης παίκτης με την μέγιστη τεχνική κατάρτιση.
    int maxInddex=-1;
    //Μεταβλητή που αποθηκεύει την ομάδα που βρίσκεται ο παίκτης με την τεχνική κατάρτισηη.
    int flag = -1;

    //Εύρεση παίκτη με την μέγιστη τεχνική κατάρτισηη στην πρώτη ομάδα.
    for(int playerIndex = 0; playerIndex<(team1.getNumberOfPlayers()); playerIndex++){
        if (maxTechnique < player[playerIndex].getTechnique()){
            maxTechnique = player[playerIndex].getTechnique();
            maxInddex = playerIndex;
            flag=0;
        }
    }

    //Τοπική αποθήκευση παικτών 1ης ομάδας.
    player=team2.getPlayers();



    //Εύρεση παίκτη με την μέγιστη τεχνική κατάρτισηη στην δεύτερη ομάδα.
    for(int playerIndex = 0; playerIndex<(team2.getNumberOfPlayers()); playerIndex++){
        if (maxTechnique < player[playerIndex].getTechnique()){
            maxTechnique = player[playerIndex].getTechnique();
            maxInddex = playerIndex;
            flag=1;
        }
    }

    //Έλεγχος αν ο παίκτης με την μέγιστη τεχνική κατάρτισηη βρίσκετα στην πρώτη ομάδα.
    if(flag=0){
        player=team1.getPlayers();
    }
    //Εκτύπωση στοιχείων παίκτη με την μέγιστη τεχνική κατάρτιση.
    player[maxInddex].status();

    //Απονομή επάθλων στον παικτη με την καλύτερη τεχνική κατάρτιση.
    player[maxInddex].setTechnique(player[maxInddex].getTechnique() + excersionAward.getTechniqueBonus());
    player[maxInddex].setPopularity(player[maxInddex].getPopularity() + excersionAward.getPopularityPenalty());

}


