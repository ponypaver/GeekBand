#include "shape.h"
#include "rectangle.h"

Rectangle::Rectangle(int n, int xx, int yy, int w, int h)
 : Shape(n), leftUp(xx, yy), width(w), height(h)
{ } 

inline double Rectangle::getArea()
{
    return width * height;
}
