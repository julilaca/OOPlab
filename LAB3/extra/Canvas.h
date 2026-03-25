#pragma once

class Canvas {
private:
    int rows, cols;
    char** grid;

public:
    Canvas(int lines, int columns);
    void set_pixel(int x, int y, char value);
    void set_pixels(int count, ...);
    void clear();
    void print();
    ~Canvas();
};
