#include "Team.h"
#include "Round.h"
#include "TeamCompetition.h"
#include "ImmunityCompetition.h"
#include "CreativityCompetition.h"
#include "FoodAward.h"
#include "ImmunityAward.h"
#include "ExcursionAward.h"

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 0;
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();
int e=0;

int main()
{
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

void normalDay()
{

    cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;

   // TODO Fill this Up!!!

   teams[0].teamEats();
   teams[0].teamWorks();
   teams[1].teamEats();
   teams[1].teamWorks();

   teams[0].teamEats();
   teams[1].teamEats();
   teams[0].teamSocializes();
   teams[1].teamSocializes();
   teams[0].teamSleeps();
   teams[1].teamSleeps();
}

void teamCompetitionDay()
{
    cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;

    // TODO Fill this Up!!!

   teams[0].teamEats();
   teams[0].teamWorks();
   teams[1].teamEats();
   teams[1].teamWorks();

   FoodAward fa;
   TeamCompetition tc(1,"Team_Competition",fa);
   e = tc.compete(teams[0],teams[1]);

   teams[0].teamEats();
   teams[1].teamEats();
   teams[0].teamSocializes();
   teams[1].teamSocializes();
   teams[0].teamSleeps();
   teams[1].teamSleeps();

}

void immunityCompetitionDay()
{

    cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;

    // TODO Fill this Up!!!

   teams[0].teamEats();
   teams[0].teamWorks();
   teams[1].teamEats();
   teams[1].teamWorks();

   ImmunityAward ia;
   ImmunityCompetition ic(2, "Immunity_Competition", ia);
   ic.compete(teams[e]);

   teams[0].teamEats();
   teams[1].teamEats();
   teams[0].teamSocializes();
   teams[1].teamSocializes();
   teams[0].teamSleeps();
   teams[1].teamSleeps();

}

void creativityCompetitionDay()
{

    cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;

    // TODO Fill this Up!!!

   teams[0].teamEats();
   teams[0].teamWorks();
   teams[1].teamEats();
   teams[1].teamWorks();

   ExcursionAward ea;
   CreativityCompetition ct(3, "Creativity_Competition", ea);
   ct.compete(teams[0], teams[1]);

   teams[0].teamEats();
   teams[1].teamEats();
   teams[0].teamSocializes();
   teams[1].teamSocializes();
   teams[0].teamSleeps();
   teams[1].teamSleeps();

}
