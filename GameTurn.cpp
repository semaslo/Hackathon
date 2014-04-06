#include <iostream>
#include "Player.h"
#include <cstdio>
#include "Country.h"
#include "Validation.h"
using namespace std;
void Build(Player* player);
void Move(Player* player);
void BuildSoldiers(Player* player);
void BuildRoad(Player* player);
extern char** roads;

extern Country** Countries;
extern int num_countries;
void GameTurn(Player* player){
    printf("Please select an option:\n");
    printf("1: Build\n");
    printf("2: Move\n");
    printf("9: I'm done\n");
    int choice;
    std::cin >> choice;
    if(choice == 1){
        Build(player);
    }
    else if(choice == 2){
        Move(player);
    }
    else{
        return;
    }
}

void Build(Player* player){
    printf("What do you want to build?\n");
    printf("1:  Soldiers\n");
    printf("2:  Roads\n");
    printf("9:  I'm done\n");
    int choice;
    std::cin >> choice;
    if(choice == 1){
        BuildSoldiers(player);
    }
    else if(choice == 2){
        BuildRoad(player);
    }
    else{
        return;
    }
}

void Move(Player* player){
    string country1 = "-1";
    string country2 = "-1";
    Country* ptr_country1 = NULL;
    Country* ptr_country2 = NULL;
    while(ptr_country1 == NULL || ptr_country2 == NULL){
        printf("From which country would you like to move soldiers?\n");
        cin>>country1;
        ptr_country1 = ValidateCountryName(country1);
        if(!HasSoldiers(ptr_country1)){
            printf("Please enter a country with soldiers.");
            ptr_country1 = NULL;
        }
        printf("To which country would you like to move soldiers?\n");
        cin>>country2;
        ptr_country2 = ValidateCountryName(country2);
        if(ptr_country1 != NULL && ptr_country2 != NULL){
            if(!IsAdjacent(ptr_country1, ptr_country2)){
                ptr_country1 = NULL;
                ptr_country2 = NULL;
            }
        }
    }
    //Moving soldiers
    vector<Building> buildings = ptr_country1->buildings;
    int size = buildings.size();
    for(int i = 0; i < size; i++){
        if(buildings[i].GetType().compare("soldier") == 0){
            ptr_country2->buildings.push_back(buildings[i]);
            ptr_country1->buildings.erase(buildings.begin()+i);
        }
    }

}

void BuildSoldiers(Player* player){
    printf("You have %d diamonds and soldiers cost 2 apiece.  How many do you want to build?\n", player->GetDiamonds());
    int number = -1;
    while(number < 0 || number*2 > player->GetDiamonds()){
        std::cin>>number;
        if(number < 0 || number*2 > player->GetDiamonds()){
            printf("Please enter a number between 0 and %d.\n", player->GetDiamonds()/2);
        }
    }
    printf("In what country would you like to build those soldiers?\n");
    std::string country_name = "0";
    cin>>country_name;
    Country* country = ValidateCountryName(country_name);
    while(country == NULL){
        printf("Please enter a valid country name.");
        cin >> country_name;
        country = ValidateCountryName(country_name);
    }
    country->buildings.push_back(Building("soldier", player, 0, 0));
    player->SpendDiamonds(2*number);
}

void BuildRoad(Player *p){
int numDiamonds=p->GetDiamonds();
int number;
Country *one;
Country *two;

printf("You have %d diamonds and roads cost 5 apiece. How many do you want to build?\n", numDiamonds);
while(true)
{
    cin>>number;
    if(number*5 > numDiamonds)
    {
        printf("Insufficient funds: Enter a new number: ");
    }
    else
        break;
}
string name;
for(int i=0; i<number; i++)
{
    while(true)
    {
        printf("Building road %d.\n",i+1);
        while(true)
        {
    printf("Enter the name of the 1st country you want the road to connect: ");
cin >> name;
if(! (one=ValidateCountryName(name)))
printf("Invalid country name.\n");
else
break;
}

while(true)
{
    printf("Enter the name of the 2nd country you want the road to connect: ");
    cin >> name;
    if(! (two=ValidateCountryName(name))){
    printf("Invalid country name.\n");
    }
    else
    break;
}
    if(!IsAdjacent(one,two)){
    printf("Cannot build a road between non-adjacent countries\n");
    }
    else
        break;


    }

roads[one->GetID()][two->GetID()]=2;
roads[two->GetID()][one->GetID()]=2;
}
}
