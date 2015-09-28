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

void init(Shape *s[], int N)
{
    srand(unsigned(time(NULL)));
    for (int n = 0, i = 0; i < N; i+=2)
    {
        s[i] = new Rectangle(++n, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1);
        s[i+1] = new Circle(++n, rand()%10+1, rand()%10+1, rand()%10+1);
    }
}

void Null_Dangling_pointer(Shape *s[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (NULL != s[i])
            s[i] = NULL;
    }
}

int main(void)
{
    const int N = 20;
    int remain;
    Shape* s[N] = {NULL};
    Shape* d[N] = {NULL};
    
    init(s, N);
    
    std::cout << "Oringal 20 shapes:" << std::endl;
    print(s, N);
    remain = removeshape(s, d);
    std::cout << std::endl << "After removed the Shapes whose area less than 50" << std::endl;
    print(d, remain);

    Null_Dangling_pointer(s, N);

    return 0;
}
