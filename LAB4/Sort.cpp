#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

Sort::Sort(int count, int min, int max) {
    srand(time(0));
    for (int i = 0; i < count; i++) {
        elements.push_back(min + rand() % (max - min + 1));
    }
}

Sort::Sort(initializer_list<int> initList) {
    elements = initList;
}

Sort::Sort(vector<int>& vec, int count) {
    for (int i = 0; i < count; i++) {
        elements.push_back(vec[i]);
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
 for (int i = 0; i < count; i++) {
        elements.push_back(va_arg(args, int));
    }

    va_end(args);
}

Sort::Sort(const string& str) {
    stringstream ss(str);
    int number;
    char comma;
    while (ss >> number) {
        elements.push_back(number);
        ss >> comma;
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < elements.size(); i++) {
        int key = elements[i];
        int j = i - 1;

        if (ascendent) {
            while (j >= 0 && elements[j] > key) {
                elements[j + 1] = elements[j];
                j--;
            }
        } else {
            while (j >= 0 && elements[j] < key) {
                elements[j + 1] = elements[j];
                j--;
            }
        }
elements[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int n = elements.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
if (ascendent) {  
    if (elements[j] > elements[j + 1])
    { swap(elements[j], elements[j + 1]);
    }
}
else {
    if (elements[j] < elements[j + 1])  { 
        swap(elements[j], elements[j + 1]);
    }
}
        }
    }
}

int Sort::partition(int left, int right, bool ascendent) {
    int pivot = elements[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (ascendent) {
            if (elements[j] <= pivot) {
                i++;
                swap(elements[i], elements[j]);
            }
        } else {
            if (elements[j] >= pivot) {
                i++;
                swap(elements[i], elements[j]);
            }
        }
    }
    swap(elements[i + 1], elements[right]);
    return i + 1;
}

void Sort::quickSortHelper(int left, int right, bool ascendent)
{
    if (left < right)
    {
        int pi = partition(left, right, ascendent);
        quickSortHelper(left, pi - 1, ascendent);
        quickSortHelper(pi + 1, right, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    if (!elements.empty())
        quickSortHelper(0, elements.size() - 1, ascendent);
}

void Sort::Print() {
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << std::endl;
}

int Sort::GetElementsCount() {
    return elements.size();
}

int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= elements.size())
        return -1;
    return elements[index];
}