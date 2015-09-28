#ifndef __CIRCLE_H__
#define __CIRCLE_H__

class Circle: public Shape
{
public:
    Circle(int n, int xx, int yy, int r);
    double getArea();

private:
    Point center;
    double radius;
};

#endif
