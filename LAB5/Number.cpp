#include "Number.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Number::Number(const char* value, int base)
{
    this->base = base;
    str = new char[strlen(value) + 1];
    strcpy(str, value);
    UpdateDecimal();
}

Number::~Number()
{
    delete[] str;
}

Number::Number(const Number& other)
{
    base = other.base;
    decimalValue = other.decimalValue;
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

Number::Number(Number&& other) 
{
    base = other.base;
    decimalValue = other.decimalValue;
    str = other.str;
    other.str = nullptr;
}

Number& Number::operator=(const Number& other)
{
    if (this != &other)
    {
        delete[] str;
        base = other.base;
        decimalValue = other.decimalValue;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    return *this;
}

Number& Number::operator=(Number&& other) 
{
    if (this != &other)
    {
        delete[] str;
        base = other.base;
        decimalValue = other.decimalValue;
        str = other.str;
        other.str = nullptr;
    }
    return *this;
}

Number& Number::operator=(int value)
{
    delete[] str;
    str = new char[32];
    itoa(value, str, 10);
    base = 10;
    decimalValue = value;
    return *this;
}

void Number::UpdateDecimal()
{
    decimalValue = strtol(str, nullptr, base);
}

void Number::UpdateString(int newBase)
{
    if (newBase == base) return;
    delete[] str;
    str = new char[32];
    itoa(decimalValue, str, newBase);
    base = newBase;
}

void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16) return;
    UpdateString(newBase);
}

void Number::Print()
{
    std::cout << str << std::endl;
}

int Number::GetDigitsCount()
{
    return strlen(str);
}

int Number::GetBase()
{
    return base; 
}

char Number::operator[](int index)
{
    if (index < 0 || index >= GetDigitsCount()) return '\0';
    return str[index];
}

Number operator+(const Number& n1, const Number& n2)
{
    int newBase = std::max(n1.base, n2.base);
    int result = n1.decimalValue + n2.decimalValue;
    Number temp("0", newBase);
    temp.decimalValue = result;
    temp.UpdateString(newBase);
    return temp;
}

Number operator-(const Number& n1, const Number& n2)
{
    int newBase = std::max(n1.base, n2.base);
    int result = n1.decimalValue - n2.decimalValue;
    Number temp("0", newBase);
    temp.decimalValue = result;
    temp.UpdateString(newBase);
    return temp;
}

Number& Number::operator+=(const Number& other)
{
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other)
{
    *this = *this - other;
    return *this;
}

bool Number::operator>(const Number& other)
{
    return decimalValue > other.decimalValue;
}

bool Number::operator<(const Number& other)
{
    return decimalValue < other.decimalValue;
}

bool Number::operator>=(const Number& other)
{
    return decimalValue >= other.decimalValue;
}

bool Number::operator<=(const Number& other)
{
    return decimalValue <= other.decimalValue;
}

bool Number::operator==(const Number& other)
{
    return decimalValue == other.decimalValue;
}

Number& Number::operator--()
{
    if (GetDigitsCount() <= 1)
    {
        decimalValue = 0;
        UpdateString(base);
        return *this;
    }
    
    int len = GetDigitsCount();
    for (int i = 0; i < len; i++) 
    {
        str[i] = str[i + 1]; 
    }
    
    UpdateDecimal();
    return *this;
}

Number Number::operator--(int)
{
    Number temp(*this);
    if (GetDigitsCount() <= 1)
    {
        decimalValue = 0;
        UpdateString(base);
        return temp;
    }
    str[GetDigitsCount() - 1] = '\0';
    UpdateDecimal();
    return temp;
}
