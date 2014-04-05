#include "Point.h"
Point::Point(int x, int y){
    Point::x = x;
    Point::y = y;
}

Point::~Point(){

}

void Point::SetCoords(int x, int y){
    Point::x = x;
    Point::y = y;
}

int Point::GetX(){
    return x;
}
int Point::GetY(){
    return y;
}
