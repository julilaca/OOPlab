#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    Sort s1(10, 2, 89);
    s1.Print();

    Sort s2({ 15, 2, 9, 1, 62 });
    s2.Print();

    int arr[] = { 3, 7, 4, 81, 2 };
    Sort s3(arr, 5);
    s3.Print();

    Sort s4(6, 11, 25, 3, 8, 19, 42);
    s4.Print();

    Sort s5("10,40,93,5,70");
    s5.Print();

    cout << "\n";

    cout << "BubbleSort ascendent: ";
    s1.BubbleSort(true);
    s1.Print();

    cout << "InsertSort ascendent: ";
    s2.InsertSort(true);
    s2.Print();

    cout << "QuickSort descendent: ";
    s5.QuickSort(false);
    s5.Print();

    return 0;
}
