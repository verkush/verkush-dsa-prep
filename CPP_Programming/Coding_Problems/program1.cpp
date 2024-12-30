// Program to write average of two numbers
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int sum = a + b;
    int avg = sum / 2;

    cout << "Average of two numbers is " << avg << endl;
    return 0;
}