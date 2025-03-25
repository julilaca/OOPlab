#include "Number.h"
#include <iostream>

int main()
{
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    std::cout << "n1 has " << n1.GetDigitsCount() << " digits\n";
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        std::cout << "n1[" << tr << "]=" << n1[tr] << "\n";
    }
    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1;
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) std::cout << "n1 > n2\n"; else std::cout << "n2 > n1\n";

    Number n4("12345", 10);
    n1 = Number("255", 10);
    n4 += n1;
    n4.Print();

    n4 = Number("13579", 10);
    n4.Print();
    --n4;
    n4.Print();
    n4--;
    n4.Print();

    return 0;
}
