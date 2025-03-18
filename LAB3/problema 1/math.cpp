#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <iostream>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}
int Math::Add(double x, double y) {
    return static_cast<int>(x + y);
}

int Math::Add(double x, double y, double z) {
    return static_cast<int>(x + y + z);
}
int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}
int Math::Mul(double x, double y) {
    return static_cast<int>(x * y);
}

int Math::Mul(double x, double y, double z) {
    return static_cast<int>(x * y * z);
}
int Math::Add(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
char* Math::Add(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return nullptr;
    }
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}
