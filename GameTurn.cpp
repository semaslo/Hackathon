#include <iostream>
#include "Player.h"
#include <cstdio>

void Build(Player* player);
void Move(Player* player);
void BuildSoldiers(Player* player);

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
    printf("9:  I'm done\n");
    int choice;
    std::cin >> choice;
    if(choice == 1){
        BuildSoldiers(player);
    }
    else{
        return;
    }
}

void Move(Player* player){

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
    //string country;

}
