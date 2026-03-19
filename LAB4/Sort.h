#pragma once
#include <vector>
#include <string>
#include <iostream>

class Sort {
private:
    std::vector<int> v;

public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> l);
    Sort(int* vector, int count);
    Sort(int count, ...);
    Sort(const char* str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
