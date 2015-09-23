#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

void remove_shape(Shape *p)
{

}

void Sort_area(Shape *p[])
{
    Shape *tmp = NULL;

    for (int i = 0; i < 20; ++i)
        for (int j = i+1; j < 20; ++j)
        {
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
        }
}

int main(void)
{
    Shape* s[20];
    srand(time(NULL));

    for (int n = 0, i = 0; i < 20; i+=2)
    {
        s[i] = new Rectangle(++n, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1);
        s[i+1] = new Circle(++n, rand()%10+1, rand()%10+1, rand()%10+1);
    }
    Sort_area(s);
    for (int i = 0; i < 20; ++i)
        std::cout << s[i]->getArea() << " " << std::endl;
//    for (int i = 0; i < 20; ++i)
//    {
//        if (s[i]->getArea() < 50)
//            remove_shape(s[i]);
//    }

    return 0;
}
