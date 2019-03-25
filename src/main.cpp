#include <iostream>
#include "list.hpp"
int main()
{
    list <int>  l;
    list <int> l1;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l1.push_back(11);
    l1.push_back(21);
    l1.push_back(31);
    std::cout <<"print list  : ";
    std::cout << l;
    std::cout <<"print list  : ";
    std::cout << l1;
    l1 = l;
    std::cout <<"print list  : ";
    std::cout << l1;
    std::cout << "List front is : ";
    l.front();
    l.insert(2,50);
    std::cout << "inserting  : ";
    std::cout << l;
    l.reverse();
    std::cout << "reverse list : ";
    std::cout << l;
    l.remove(0);
    std::cout << "deleting : ";
    std::cout << l;
    l.pop_back();
    std::cout << "pop_back : ";
    std::cout << l;
    l.pop_back();
    std::cout << "pop_back : ";
    std::cout << l;
    l.pop_back();
    std::cout << "pop_back : ";
    std::cout << l;
}


