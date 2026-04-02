#pragma once
#include <vector>
#include <string>
#include <cstdarg>
#include <initializer_list>
using namespace std;

class Sort {
private:
    vector<int> elements;
    void quickSortHelper(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);

public:
    Sort(int count, int min, int max);
    Sort(initializer_list<int> initList);
    Sort(vector<int>& vec, int count);
    Sort(int count, ...);
    Sort(const string& str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

};


