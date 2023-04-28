#include <iostream>
using namespace std;

bool primilityTest1(int input)
{ //time comp = o(n)
    if (input == 1)
        return 0;
    for (int i = 2; i <= input / 2; i++)
    {
        if (input % i == 0)
            return 0;
    }
    return 1;
}
bool primalityTestOptimised(int n)
{
    //time complixity = sqrt(n)/2;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i+= 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int input;
    cin >> input;
    cout << primilityTest1(input);
    return 0;
}
