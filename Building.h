#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "Point.h"
#include "Player.h"

class Building{
    public:
        //Constructor
        Building(char* type, Player* owner, int x, int y);
        //Destructor
        ~Building();
        //Setting variables
        void SetPosition(int x, int y);
        void SetPosition(Point* point);
        //Getting
        Point* GetPosition();
        char* GetType();
        Player* GetOwner();
    private:
        //Position
        Point* pos;
        //Type of building
        char* type;
        //Player who owns building, NULL if no owner
        Player* owner;
};

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
#endif // BUILDING_H_INCLUDED
