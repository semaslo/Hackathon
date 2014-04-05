#include <string>
#include "Country.h"
using namespace std;
extern int num_countries;

bool ValidateCountryName(string name, Country* countries){
    for(int i = 0; i < num_countries; i++){
        Country* country = &(countries[i]);
        if(country->GetName().compare(name) == 0){
            return true;
        }
    }
    return false;
}
