#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int w, int h) {
    width = w;  
    height = h;

    matrix = new char*[h]; 
    for (int i = 0; i < h; i++) {
        
        matrix[i] = new char[w]; 

        for (int j = 0; j < w; j++) {
            matrix[i][j] = ' '; 
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i <= 2 * ray; ++i) {
        for (int j = 0; j <= 2 * ray; ++j) {
            int dx = i - ray;
            int dy = j - ray;
            if ((dx * dx + dy * dy) <= ray * ray) {
                int px = x + dx;
                int py = y + dy;
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    matrix[py][px] = ch;
                }
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i <= 2 * ray; ++i) {
        for (int j = 0; j <= 2 * ray; ++j) {
            int dx = i - ray;
            int dy = j - ray;
            if ((dx * dx + dy * dy) <= ray * ray) {
                int px = x + dx;
                int py = y + dy;
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    matrix[py][px] = ch;
                }
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; ++i) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int j = top; j <= bottom; ++j) {
        SetPoint(left, j, ch);
        SetPoint(right, j, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 > x1 ? x2 - x1 : x1 - x2;
    int dy = y2 > y1 ? y2 - y1 : y1 - y2;
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
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
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}
