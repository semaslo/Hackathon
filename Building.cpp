#include "Point.h"
#include "Player.h"
#include <cstdio>
#include <stdlib.h>
#include <string>
#include "Building.h"
Building::Building(char* type, Player* owner, int x, int y){
    Building::owner = owner;
    Building::type = (char*)malloc(strlen(type)*sizeof(char));
    Building::pos = new Point(x, y);
}

Building::~Building(){
    Building::pos->~Point();
    free(type);
}

void Building::SetPosition(int x, int y){
    Building::pos->SetCoords(x, y);
}

void Building::SetPosition(Point* point){
    Building::pos->SetCoords(point->GetX(), point->GetY());
}
Player* Building::GetOwner(){
    return owner;
}

char* Building::GetType(){
    return type;
}

Point* Building::GetPosition(){
    return pos;
}
