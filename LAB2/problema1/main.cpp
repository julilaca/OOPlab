#include <iostream>
#include "NumberList.h"

int main() {
    NumberList list;

    list.Init();
    list.Add(5);
    list.Add(3);
    list.Add(8);
    list.Add(1);
    list.Print();
    list.Sort();

    std::cout << "after sorting:";
    list.Print();

    return 0;
}
