#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <algorithm>
#include <cstring>

using namespace std;

Sort::Sort(int count, int min, int max) {
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        v.push_back(min + rand() % (max - min + 1));
    }
}

Sort::Sort(std::initializer_list<int> l) {
    for (int elem : l) {
        v.push_back(elem);
    }
}

Sort::Sort(int* vector, int count) {
    for (int i = 0; i < count; i++) {
        v.push_back(vector[i]);
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        v.push_back(va_arg(args, int));
    }
    va_end(args);
}

Sort::Sort(const char* str) {
    char* strCopy = strdup(str);
    char* token = strtok(strCopy, ",");
    while (token != nullptr) {
        v.push_back(stoi(token));
        token = strtok(nullptr, ",");
    }
    free(strCopy);
}

void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? v[j] > key : v[j] < key)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    bool swapped;
    for (size_t i = 0; i < v.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < v.size() - i - 1; j++) {
            if ((ascendent && v[j] > v[j + 1]) || (!ascendent && v[j] < v[j + 1])) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int Partition(vector<int>& v, int low, int high, bool ascendent) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((ascendent && v[j] < pivot) || (!ascendent && v[j] > pivot)) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void QuickSortHelper(vector<int>& v, int low, int high, bool ascendent) {
    if (low < high) {
        int p = Partition(v, low, high, ascendent);
        QuickSortHelper(v, low, p - 1, ascendent);
        QuickSortHelper(v, p + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(v, 0, v.size() - 1, ascendent);
}

void Sort::Print() {
    for (int elem : v) {
        cout << elem << ' ';
    }
    cout << endl;
}

int Sort::GetElementsCount() {
    return v.size();
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < v.size()) {
        return v[index];
    }
    return -1;
}
