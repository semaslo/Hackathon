#include <string>
#include "Country.h"
#include <vector>
#include "Building.h"
using namespace std;

extern bool** roads;
extern int num_countries;
extern Country** Countries;
Country* ValidateCountryName(string name){
    for(int i = 0; i < num_countries; i++){
        Country* country = Countries[i];
        if(country->GetName().compare(name) == 0){
            return country;
        }
    }
    return NULL;
}

bool HasSoldiers(Country* country){
    if(country == NULL){
        return false;
    }
    vector<Building> buildings = country->buildings;
    int size = buildings.size();
    for(int i = 0; i < size; i++){
        Building building = buildings[i];
        if(building.GetType().compare("soldeir")){
            return true;
        }
    }
    return false;
}

bool IsAdjacent(Country* one, Country* two){
    int country1 = one->GetID();
    int country2 = two->GetID();
    if(roads[country1][country2] > 0){
        return true;
    }
    return false;
}
