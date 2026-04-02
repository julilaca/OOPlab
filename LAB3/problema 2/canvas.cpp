#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int w, int h) {
    width = w;
    height = h;

    matrix = new char*[w];
    for (int i = 0; i < w; i++) {
        matrix[i] = new char[h];
        for (int j = 0; j < h; j++) {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < width; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[x][y] = ch;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = -ray; i <= ray; i++) {
        for (int j = -ray; j <= ray; j++) {
            if (i * i + j * j <= ray * ray) {
                SetPoint(x + i, y + j, ch);
            }
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    FillCircle(x, y, ray, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int x = left; x <= right; x++) {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    for (int y = top; y <= bottom; y++) {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int y = top; y <= bottom; y++)
        if ( y   % 2 == 1) {
        for (int x = left; x <= right; x++) {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 > x1 ? x2 - x1 : x1 - x2;
    int dy = y2 > y1 ? y2 - y1 : y1 - y2;
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << matrix[x][y];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            matrix[x][y] = ' ';
        }
    }
}
