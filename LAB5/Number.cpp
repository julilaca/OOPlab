#include "Number.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Number::Number(const char* value, int base) : base(base)
{
    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
    UpdateDecimal();
}

Number::~Number()
{
    delete[] value;
}

Number::Number(const Number& other)
{
    base = other.base;
    decimalValue = other.decimalValue;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) noexcept
{
    base = other.base;
    decimalValue = other.decimalValue;
    value = other.value;
    other.value = nullptr;
}

Number& Number::operator=(const Number& other)
{
    if (this != &other)
    {
        delete[] value;
        base = other.base;
        decimalValue = other.decimalValue;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept
{
    if (this != &other)
    {
        delete[] value;
        base = other.base;
        decimalValue = other.decimalValue;
        value = other.value;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(int value)
{
    delete[] this->value;
    this->value = new char[32];
    itoa(value, this->value, 10);
    base = 10;
    decimalValue = value;
    return *this;
}

void Number::UpdateDecimal()
{
    decimalValue = strtol(value, nullptr, base);
}

void Number::UpdateString(int newBase)
{
    if (newBase == base) return;
    delete[] value;
    value = new char[32];
    itoa(decimalValue, value, newBase);
    base = newBase;
}

void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16) return;
    UpdateString(newBase);
}

void Number::Print()
{
    std::cout << value << std::endl;
}

int Number::GetDigitsCount()
{
    return strlen(value);
}

int Number::GetBase()
{
    return base;
}

char Number::operator[](int index)
{
    if (index < 0 || index >= GetDigitsCount()) return '\0';
    return value[index];
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
    memmove(value, value + 1, GetDigitsCount());
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
    value[GetDigitsCount() - 1] = '\0';
    UpdateDecimal();
    return temp;
}
