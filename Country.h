#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED

#include <vector>

using namespace std;
class Country{
public:
    Country(Point* pos, float radius);
    ~Country();
    Point* GetCenter();
    float GetRadius();
private:
    Point* center;
    float radius;
    vector<Building> buildings;
};

Country::Country(Point* pos, float radius){
    Country::center = pos;
    Country::radius = radius;
    buildings = vector<Building>();
}

Country::~Country(){
    free(center);
}

Point* Country::GetCenter(){
    return center;
}

float Country::GetRadius(){
    return radius;
}

#endif // COUNTRY_H_INCLUDED
