#include <iostream>
#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << lst + 0 << std::endl;
    std::cout << lst[0] << std::endl;
    std::cout << lst[0] << std::endl;
}