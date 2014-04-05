#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Country.h"

using namespace std;
Player *player;
Country *country;
bool **adjacencies;
int numPlayers;

void setup(){
string input="";

//Get the number of players
cout << "Please enter the number of players. The maximum number of players is 10: ";
while(true)
{
getline(cin, input);
stringstream myStream(input);
if(!(myStream >> numPlayers)|| numPlayers<0 || numPlayers>10)
{
cout << "Please enter an integer less than or equal to 10: ";
}
else
break;
}
cout << "The number of players is " << numPlayers << endl;

//Construct the players
player = new Player[numPlayers];

//Get the player names
string name="";
for(int i=1; i<=numPlayers; i++)
{
cout << "Please enter the name for player " << i << ": ";
while(true)
{
if(!(cin >> name))
{
cout << "Please enter a name: ";
}
else
break;
}
cout << "The name of player " << i << " is " << name << endl;
player[i-1].SetName(name);
}
}
