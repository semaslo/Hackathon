#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

Country* ValidateCountryName(string name);
bool HasSoldiers(Country* country);
bool IsAdjacent(Country* one, Country* two);


#endif // VALIDATION_H_INCLUDED
