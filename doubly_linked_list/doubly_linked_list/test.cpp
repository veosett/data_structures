#include <iostream>
#include "dl_list.h"

int main()
{
    dl_list<int> dll;

    dll.push_front(8);
    dll.push_back(5);
    dll.push_back(7);
    dll.push_front(10);
    dll.push_front(111);
    dll.push_back(13);
    dll.push_back(1599);

    for (int i = 0; i < 7; i++)
    {
        std::cout << "elem:  " << dll.front() << std::endl;
        std::cout << "size:  " << dll.size() << std::endl;
        std::cout << "empty: " << dll.empty() << std::endl;
        std::cout << std::endl;
        dll.pop_front();
    }

    getchar();

    return 0;
}