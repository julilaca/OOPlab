#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex operator+(const Complex& l, const Complex& r) {
    return { l.real() + r.real(), l.imag() + r.imag() };
}

Complex operator+(const Complex& l, double r) {
    return { l.real() + r, l.imag() };
}

Complex operator+(double l, const Complex& r) {
    return r + l;
}

Complex operator-(const Complex& l, const Complex& r) {
    return { l.real() - r.real(), l.imag() - r.imag() };
}

Complex operator-(const Complex& l, double r) {
    return { l.real() - r, l.imag() };
}

Complex operator-(double l, const Complex& r) {
    return { l - r.real(), -r.imag() };
}

Complex operator*(const Complex& l, const Complex& r) {
    return {
        l.real() * r.real() - l.imag() * r.imag(),
        l.real() * r.imag() + l.imag() * r.real()
    };
}

Complex operator*(const Complex& l, double r) {
    return { l.real() * r, l.imag() * r };
}

Complex operator*(double l, const Complex& r) {
    return r * l;
}

Complex operator-(const Complex& obj) {
    return { -obj.real(), -obj.imag() };
}

bool operator==(const Complex& l, const Complex& r) {
    return std::abs(l.real() - r.real()) < 1e-9 && std::abs(l.imag() - r.imag()) < 1e-9;
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

Complex& Complex::operator++() {
    ++real_data;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    --real_data;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    bool has_real = std::abs(c.real()) > 1e-9;
    bool has_imag = std::abs(c.imag()) > 1e-9;

    if (!has_real && !has_imag) {
        out << "0";
    } else if (has_real && !has_imag) {
        out << c.real();
    } else if (!has_real && has_imag) {
        out << c.imag() << "i";
    } else {
        out << c.real() << (c.imag() >= 0 ? " + " : " - ") << std::abs(c.imag()) << "i";
    }

    return out;
}

