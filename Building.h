#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "Player.h"
#include "Point.h"
#include <string>
using namespace std;
class Building{
    public:
        //Constructor
        Building(string type, Player* owner, int x, int y);
        //Destructor
        ~Building();
        //Setting variables
        void SetPosition(int x, int y);
        void SetPosition(Point* point);
        //Getting
        Point* GetPosition();
        string GetType();
        Player* GetOwner();
    private:
        //Position
        Point* pos;
        //Type of building
        string type;
        //Player who owns building, NULL if no owner
        Player* owner;
};

#endif // BUILDING_H_INCLUDED
