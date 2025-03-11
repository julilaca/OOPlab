#include "Canvas.h"

int main() {

 Canvas canvas(35, 20);
    canvas.SetPoint(0, 0, '8');
    canvas.DrawLine(0, 1, 20, 1, '+');
    canvas.DrawRect(5, 4, 10, 7, '#');
    canvas.FillRect(15, 4, 20, 8, '*');
    canvas.DrawCircle(10, 15, 3, 'o');
    canvas.FillCircle(25, 14, 5, '1');

    canvas.Print();
    canvas.Clear();
    canvas.Print();

    return 0;
}
