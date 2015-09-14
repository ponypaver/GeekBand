#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"

#define debug 0

int main(void)
{
#if debug
    date ad[5] = {date(1,0,6), date(1,0,1), date(1,1,2), date(1,0,3), date(1,0,4)};
    Sort(ad, 5);
    print(ad, 5);
#endif
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
