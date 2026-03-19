#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

Sort::Sort(int count, int min, int max) {
    srand(time(0));
    for (int i = 0; i < count; i++) {
        v.push_back(min + rand() % (max - min + 1));
    }
}

Sort::Sort(initializer_list<int> l) {
    const int* it = l.begin();
    for (int i = 0; i < static_cast<int>(l.size()); i++) {
        v.push_back(it[i]);
    }
}

Sort::Sort(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        v.push_back(arr[i]);
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
    stringstream ss(str);
    int num;
    char ch;
    while (ss >> num) {
        v.push_back(num);
        ss >> ch;
    }
}

void Sort::InsertSort(bool ascendent) {
    int n = static_cast<int>(v.size());
    for (int i = 1; i < n; i++) {
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
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascendent ? v[j] > v[j + 1] : v[j] < v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void qSort(vector<int>& vec, int low, int high, bool asc) {
    if (low >= high) return;
    int pivot = vec[high], i = low;
    for (int j = low; j < high; j++) {
        if (asc ? vec[j] < pivot : vec[j] > pivot) {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[high]);
    qSort(vec, low, i - 1, asc);
    qSort(vec, i + 1, high, asc);
}

void Sort::QuickSort(bool ascendent) {
    if (v.size() > 0) {
        qSort(v, 0, static_cast<int>(v.size()) - 1, ascendent);
    }
}

void Sort::Print() {
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int Sort::GetElementsCount() {
    return static_cast<int>(v.size());
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < static_cast<int>(v.size())) {
        return v[index];
    }
    return -1;
}
