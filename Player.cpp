#include <string>
#include "Player.h"

Player::Player(){
   this->diamonds = 20;
}

void Player::AddDiamonds(int diamonds){
   this->diamonds += diamonds;
}

void Player::SpendDiamonds(int diamonds){
   if(diamonds <= Player::diamonds){
       this->diamonds -= diamonds;
   }
   else{
       throw 10;
   }
}

int Player::GetDiamonds(){
   return diamonds;
}

void Player::SetName(std::string name)
{
this->name=name;
}

std::string Player::GetName()
{
return name;
}
