#ifndef POINT_H_
#define POINT_H_
#include<initializer_list>

class Point
{
private:
public:
    int x, y;
    Point(int x, int y);
    Point(std::initializer_list<int> list);
    Point operator+(const Point & right);

    bool isValid();

    ~Point();
};



#endif // POINT_H_