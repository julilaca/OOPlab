#include "Canvas.h"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) : rows(lines), cols(columns) {
    grid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
    }
    clear();
}

void Canvas::clear() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            grid[i][j] = ' ';
}
void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < rows && y >= 0 && y < cols)
        grid[x][y] = value;
}
void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
int x = va_arg(args, int);
int y = va_arg(args, int);
int val = va_arg(args, int);
set_pixel(x, y, static_cast<char>(val));
    }
    va_end(args);
}

void Canvas::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j];
        } std::cout << '\n';
    }
}
Canvas::~Canvas() {
    for (int i = 0; i < rows; ++i)
        delete[] grid[i];
    delete[] grid;
}
