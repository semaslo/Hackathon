#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED

#include <vector>
#include "Point.h"
#include "Building.h"
#include <string>
using namespace std;
class Country{
public:
    Country(Point* pos, float radius, string name);
    ~Country();
    Point* GetCenter();
    float GetRadius();
    string GetName();
    std::vector<Building> buildings;
private:
    Point* center;
    float radius;

    string name;
};
#endif // COUNTRY_H_INCLUDED
