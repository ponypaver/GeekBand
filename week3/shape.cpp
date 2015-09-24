#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

void Sort_area(Shape *p[])
{
    Shape *tmp = NULL;

    for (int i = 0; i < 20; ++i)
        for (int j = i+1; j < 20; ++j)
        {
            if (p[i]->getArea() < p[j]->getArea()) {
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
            }
        }
}

void print(Shape *s[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << s[i]->getArea() << (i == n - 1? "\n" : " ");

}

int removeshape(Shape *s[])
{
    int remain;
    for (int i = 0; i < 20; ++i)
    {
        if (s[i]->getArea() >= 50)
        {
            remain = i + 1;
            continue;
        }
        else
        {
            delete s[i];
        }
    }

    return remain;
}

int main(void)
{
    int remain;
    Shape* s[20];
    srand(time(NULL));

    for (int n = 0, i = 0; i < 20; i+=2)
    {
        s[i] = new Rectangle(++n, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1);
        s[i+1] = new Circle(++n, rand()%10+1, rand()%10+1, rand()%10+1);
    }
    std::cout << "Oringal 20 shapes:" << std::endl;
    Sort_area(s);
    print(s, 20);
    remain = removeshape(s);
    std::cout << std::endl << "After removed the Shapes whose area less than 50" << std::endl;
    print(s, remain);

    return 0;
}
