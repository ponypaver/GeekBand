#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

void print(Shape *s[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << s[i]->getArea() << (i == n - 1? "\n" : " ");

}

int removeshape(Shape *s[], Shape* d[])
{
    int remain = 0, j = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (s[i]->getArea() >= 50)
        {
            remain++ ;
            d[j++] = s[i];
            s[i] = NULL;
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
    Shape* d[20];

    srand(time(NULL));

    for (int n = 0, i = 0; i < 20; i+=2)
    {
        s[i] = new Rectangle(++n, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1);
        s[i+1] = new Circle(++n, rand()%10+1, rand()%10+1, rand()%10+1);
    }
    std::cout << "Oringal 20 shapes:" << std::endl;
    print(s, 20);
    remain = removeshape(s, d);
    std::cout << std::endl << "After removed the Shapes whose area less than 50" << std::endl;
    print(d, remain);

    return 0;
}
