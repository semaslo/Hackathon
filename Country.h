#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED

#include <vector>
#include "Point.h"
#include "Building.h"
#include <string>
using namespace std;

class Country{
public:
    Country(Point pos, float radius, string name, int countryID);
    ~Country();
    Point* GetCenter();
    float GetRadius();
    string GetName();
    vector<Building> buildings;
    int GetID();
private:
    Point* center;
    float radius;
    int countryID;
    string name;
};

#endif // COUNTRY_H_INCLUDED
