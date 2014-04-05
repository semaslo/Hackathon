#include <vector>
#include "Point.h"
#include "Building.h"
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "Country.h"
using namespace std;


Country::Country(Point* pos, float radius, string name){
    Country::center = pos;
    Country::radius = radius;
    Country::buildings = vector<Building>();
    Country::name = name;
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

string Country::GetName(){
    return Country::name;
}
