/*#include <stdlib.h>
#include <iostream>
#include <string>*/

#include "TeamCompetition.h"

using namespace std;

//constructors,destructor
TeamCompetition::TeamCompetition()
{
    //foodAward;
    rounds = new Round[3];
}

TeamCompetition::TeamCompetition(int i, string n, FoodAward fa):Competition(id, n)
{
    foodAward = fa;
    rounds = new Round[3] {Round(1,10800,""),Round(2,10800,""),Round(3,10800,"")};

}

TeamCompetition::~TeamCompetition()
{
        delete [] rounds;
        //cout << "Destroyed!"<< endl;
}

//setters
void TeamCompetition::setFoodAward(FoodAward fa)
{
    foodAward = fa;
}

//getters
 Round* TeamCompetition::getRounds()
{
    return rounds;
}
FoodAward TeamCompetition::getFoodAward()
{
    return foodAward;
}

//other functions
void TeamCompetition::status(){
    foodAward.status();
    for(int k=0;k<3;k++)
    {
        rounds[k].status();
    }
}

int TeamCompetition::compete(Team &team1, Team &team2){
    //Δήλωση 2 πινάκων για τοπική αποθήκευση παικτών κάθε ομάδας.
    Player *player,*player2;
    player = new Player[team1.getNumberOfPlayers()];
    player2 = new Player[team2.getNumberOfPlayers()];

    //Τοπική αποθήκευση παικτών.
    player=team1.getPlayers();
    player2=team2.getPlayers();

    //Νίκες κάθε ομάδας ανά γύρω.
    int wins1=0;
    int wins2=0;

    //Πίνακες για να αποθηκεύεται η σειρά των τυχαίων παικτών που θα λάβουν μέρος.
    int playersteam1[5];
    int playersteam2[5];

    //Μέση τεχνικλη κατάρτιση κάθε ομάδας.
    float meshTechnique1=0;
    float mashTechnique2=0;

    //Μέση κούραση κάθε ομάδας.
    float meshFatigue1=0;
    float meshFatigue2=0;

    //Πραγματοποίηση κάθε γύρου.
    for(int round=0; round < 3; round++)
    {
        for(int i=0; i<5; i++)
        {
            //Εύρεση τυχαίων παικτών.
            playersteam1[i] = rand() % 11;
            playersteam2[i] = rand() % 11;

            //Κάθε παίκτης αγωνίζεται.
            player[playersteam1[i]].compete();
            player2[playersteam2[i]].compete();

            //Άθροιση τεχνικής κατάρτισης κάθε παίκτη αφού αγωνιστεί για εύρεση μέσης τεχνικής κατάρτισης.
            meshTechnique1 += player[playersteam1[i]].getTechnique();
            mashTechnique2 += player[playersteam2[i]].getTechnique();

            //Άθροιση κούρασης κάθε παίκτη αφού αγωνιστεί για εύρεση μέσης κούρασης.
            meshFatigue1 += player[playersteam1[i]].getFatigue();
            meshFatigue2 += player2[playersteam2[i]].getFatigue();

        }

        //Τελικός υπολογισμός μέσης τεχνικης κατάρτισης.
        meshTechnique1 = meshTechnique1/5.00;
        mashTechnique2 = mashTechnique2/5.00;

        //Τελικός υπολογισμός μέσης κούρασης.
        meshFatigue1 = meshFatigue1/5.00;
        meshFatigue2 = meshFatigue2/5.00;

        //Έλεγχος για εύρεση και αποθήκευση νικητήριας ομάδας γύρου.
      if(meshTechnique1 > mashTechnique2)
        {
            wins1++;
            rounds[round].setWinner("Blue");
        }
        else if(mashTechnique2 > meshTechnique1)
        {
            wins2++;
            rounds[round].setWinner("Red");
        }
        else
        {
            if(meshFatigue1 < meshFatigue2)
            {
                wins1++;
                rounds[round].setWinner("Blue");
            }
            else if (meshFatigue2 < meshFatigue1)
            {
                wins2++;
                rounds[round].setWinner("Red");
            }
        }
    }

    //Έκτύπωση αριθμών νικών κάθε ομάδας.
    cout<<"Team 1 win "<< wins1 <<" times."<<endl;
    cout<<"Team 2 win "<< wins2 <<" times."<<endl;

    //Έλεγχος για εύρεση συνολικής νικήτριας ομάδας διαγωνισμού και επιστροφή.
    if(wins1 >= wins2)
    {
        //Αύξση νικών ομάδας, απονομή επάθλου και επιστροφή.
        team1.setWins(team1.getWins() + 1);
        team1.setSupplies(team1.getSupplies() + foodAward.getBonusSupplies());
        return 1;
    }
    else
    {
        //Αύξση νικών ομάδας, απονομή επάθλου και επιστροφή.
        team2.setWins(team2.getWins() + 1);
        team2.setSupplies(team2.getSupplies() + foodAward.getBonusSupplies());
        return 0;
    }
}


















