#include "Sort.h"

int main() {
    Sort s1(10, 1, 100);
    s1.Print();

    Sort s2({5, 3, 8, 1, 2});
    s2.Print();

    std::vector<int> vec = {9, 7, 5, 11, 12};
    Sort s3(vec, vec.size());
    s3.Print();

    Sort s4(5, 10, 20, 30, 40, 50);
    s4.Print();

    Sort s5("10,40,100,5,70");
    s5.Print();

    s1.InsertSort(true);
    s1.Print();

    s2.QuickSort(false);
    s2.Print();

    s3.BubbleSort(true);
    s3.Print();

    return 0;
}
