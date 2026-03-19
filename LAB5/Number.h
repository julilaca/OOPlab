#ifndef NUMBER_H
#define NUMBER_H

#include <cstring>
#include <algorithm>

class Number
{
private:
    char* value;
    int base;
    int decimalValue;
    void UpdateDecimal();
    void UpdateString(int newBase);

public:
    Number(const char* value, int base);
    ~Number();
    Number(const Number& other);
    Number(Number&& other);
    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int value);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();

    char operator[](int index);
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    bool operator>(const Number& other);
    bool operator<(const Number& other);
    bool operator>=(const Number& other);
    bool operator<=(const Number& other);
    bool operator==(const Number& other);
    Number& operator--();
    Number operator--(int);
};

#endif