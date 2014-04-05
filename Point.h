#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class Point{
public:
    Point(int x, int y);
    ~Point();
    void SetCoords(int x, int y);
    int GetX();
    int GetY();
private:
    int x;
    int y;
};

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
#endif // POINT_H_INCLUDED
