#include <iostream>

using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    int n;
    cout << "Enter number to find Factorial : ";
    cin >> n;

    int factorial = fact(n);

    cout << "Factorial of " << n << " is : " << factorial << endl;

    return 0;
}