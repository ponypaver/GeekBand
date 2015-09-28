#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle: public Shape
{
public:
    Rectangle(int n, int xx, int yy, int w, int h);
    double getArea();

private:
    int width;
    int height;
    Point leftUp;
};

#endif
