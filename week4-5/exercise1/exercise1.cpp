#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(void)
{
    int a[] = {0, 0, 30, 20, 0, 0, 0, 0, 10, 0};
    std::vector<int> v1(a, a + 10);
    std::vector<int> v2;
    std::vector<int>::iterator it = v1.begin();
    
    while (v1.end() != (it = std::find_if(it, v1.end(), std::bind2nd(std::not_equal_to<int>(), 0)))) {
        v2.push_back(*it);
        ++it;
    }

    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}
