#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream> 

Sort::Sort(int count, int min, int max) {
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        elements.push_back(min + rand() % (max - min + 1));
    }
}
Sort::Sort(std::initializer_list<int> initList) : elements(initList) {}

Sort::Sort(const std::vector<int>& vec, int count) {
    for (int i = 0; i < count; ++i) {
        elements.push_back(vec[i]);
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        elements.push_back(va_arg(args, int));
    }
    va_end(args);
}

Sort::Sort(const std::string& str) {
    std::stringstream ss(str);
    int number;
    char comma;
    while (ss >> number) {
        elements.push_back(number);
        ss >> comma;
    }
}
void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < elements.size(); ++i) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = key;
    }
}
void Sort::QuickSort(bool ascendent) {
    quickSortHelper(0, elements.size() - 1, ascendent);
}

void Sort::quickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = partition(low, high, ascendent);
        quickSortHelper(low, pi - 1, ascendent);
        quickSortHelper(pi + 1, high, ascendent);
    }
}

int Sort::partition(int low, int high, bool ascendent) {
    int pivot = elements[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (ascendent ? elements[j] < pivot : elements[j] > pivot) {
            ++i;
            std::swap(elements[i], elements[j]);
        }
    }
    std::swap(elements[i + 1], elements[high]);
    return i + 1;
}

void Sort::BubbleSort(bool ascendent) {
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        for (size_t j = 0; j < elements.size() - i - 1; ++j) {
            if (ascendent ? elements[j] > elements[j + 1] : elements[j] < elements[j + 1]) {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::Print() {
    for (int elem : elements) {
        std::cout << elem << " ";
    }  std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return elements.size();
}
int Sort::GetElementFromIndex(int index) {
  return elements[index];
}
