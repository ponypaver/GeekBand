#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"

int main(void)
{
    const int n = 10;
    date d1, *pd = NULL;
    std::cout<< "Create " << n << " random dates: " << std::endl;
    pd = CreatePoints(n);
    print(pd, n);

    std::cout<< "dates after sorted: " << std::endl;
    Sort(pd, n);
    print(pd, n);
    
    delete[] pd;

    return 0;
}
