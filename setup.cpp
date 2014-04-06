#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Country.h"
#include <stdlib.h>

using namespace std;
int numPlayers;
extern Country** Countries;
extern int num_countries;
Player *player;
Country *country;
char **roads;

//Function prototypes
extern int num_countries;
extern Country** Countries;
void setup();
void InitiatePlayers();
void InitiateRoads(char* name);

void setup(){
	//Set up the Players
	InitiatePlayers();
	//Set up the Roads
	InitiateRoads("CountryAdjacencies.txt");
}

void InitiatePlayers()
{
	string input;
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
	player= new Player[numPlayers];

	//Get the player names
	string name;

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

void InitiateRoads(char* filename){
	//Create the roads adjacency matrix
	roads = (char**)calloc(num_countries, sizeof(char*));
	//roads=(char**) malloc(sizeof(char*)*num_countries);
	for(int i=0; i<num_countries; i++)
	{
		roads[i]=(char*)calloc(num_countries, sizeof(char));
	}
	//Add in 1's in all the appropriate places for countries that can be connected
	int x, y;
	FILE* file=fopen(filename,"rb");
	if(file==NULL){
		printf("File did not open");
		return;
	}
	while(!feof(file))
	{
		int error=fscanf(file,"%d %d\n", &x, &y);
		if(error!=2 || x<0 || x>num_countries || y<0 || y>num_countries)
		{
			printf("Improperly formatted Adjacencies file!");
			return;
		}
		roads[x][y]=1;
		printf("%d %d\n", x, y);
		printf("%s", roads[y]);
		roads[y][x]=1;
	}
}


void InitiateCountries(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("File did not open");
        return;
    }
    fscanf(file, "%d\n", &num_countries);
    char name[20];
    int x;
    int y;
    Countries = (Country**)calloc(num_countries, sizeof(Country*));
    for(int i = 0; i < num_countries; i++){
        fscanf(file, "%s %d %d\n", name, &x, &y);
        string string_name(name);
        cout << string_name << endl;
        cout << x << " " << y << endl;
        Countries[i] = new Country(Point(x, y), 100.0f, string_name, i);
    }
}
