#include <cmath>
#include "shape.h"
#include "circle.h"

Circle::Circle(int n, int xx, int yy, int r)
 : Shape(n), center(xx, yy), radius(r)
{ }

inline double Circle::getArea()
{
    return M_PI * radius * radius;
}
