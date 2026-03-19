#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int t = 2; t < n / 2; t++)
        if ((n % t) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    if (isPrime(n))
    cout << n << " is prime !";
    else
    cout << n << " is NOT prime !";
    return 0;
}
