#ifndef __MY_CIRCLE_H__
#define __MY_CIRCLE_H__

class Circle: public Shape
{
public:
    Circle(int n, int xx, int yy, int r);
    int getArea();

private:
    Point center;
    int radius;
};

#endif
