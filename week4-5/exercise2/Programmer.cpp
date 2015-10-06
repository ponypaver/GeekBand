#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include "programmer.h"

int main(void)
{
    std::set<Programmer>::iterator it;
    std::set<Programmer, ProgrammerIdGreater> setprogrammers;
    Programmer pa[] = {
        Programmer(1, "Scott Meyers"), 
        Programmer(2, "Martin Fowler"), 
        Programmer(3, "Bill Gates"), 
        Programmer(4, "P.J. Plaught"), 
        Programmer(5, "Stanley B. Lippman"), 
        Programmer(6, "Andrei Alexandrescu")
        };

    // (1)
    setprogrammers.insert(pa, pa + 6);
    
    // (2)
    for_each(setprogrammers.begin(), setprogrammers.end(), std::mem_fun_ref(&Programmer::Print));

    // (3)
    if (setprogrammers.end() != (it = setprogrammers.find(Programmer(3, "Bill Gates")))) {
        std::cout << std::endl << "We have found: ";
        (*it).Print();
    // (4)
        //it->Name = "David Vandevoorde"; // Cannot pass compile, because key of set is const;
        std::cout << "Replace him with David" << std::endl;
        setprogrammers.erase(*it);
        setprogrammers.insert(Programmer(3, "David Vandevoorde"));
        for_each(setprogrammers.begin(), setprogrammers.end(), std::mem_fun_ref(&Programmer::Print));
    }
    else
        std::cout << "We haven't found Gates" << std::endl;
    
    // (5)
    std::set<Programmer, ProgrammerNameComparer> set2;
    set2.insert(pa, pa + 6);
    
    // (6)
    std::cout << std::endl << "Sort by name: " << std::endl;
    for_each(set2.begin(), set2.end(), std::mem_fun_ref(&Programmer::Print));

    return 0;
}
