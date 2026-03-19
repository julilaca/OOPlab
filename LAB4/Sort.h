#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <cstdarg>
#include <initializer_list>

class Sort {
private:
    std::vector<int> elements;

public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> initList);
    Sort(const std::vector<int>& vec, int count);
    Sort(int count, ...);
    Sort(const std::string& str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

private:
    void quickSortHelper(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);
};

#endif
