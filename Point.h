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


#endif // POINT_H_INCLUDED
