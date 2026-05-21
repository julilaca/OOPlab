#include <cstdio>
#include "Vector.h"

float operator"" _Kelvin(unsigned long long k) {
    return (float)k - 273.15f; }

float operator"" _Fahrenheit(unsigned long long f) {
    return ((float)f - 32.0f) * 5.0f / 9.0f; }

int compare_ints(int x, int y) {
    if (x < y) return -1;
    if (x > y)return 1;
return 0;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    Vector<int> v;

    // index, element
    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);

    Vector<int> w = v;
    
    // index
    v.remove(0);
    v.sort(compare_ints);
    printf("%d\n", w[0]);

    v.print();

    return 0;
}