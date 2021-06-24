#include <bits/stdc++.h>
using namespace std;

// 0 1 1 2 3 5 8 ...
int fibonacci(int n)
{
    if (n < 0)
        return 0;
    else if (n <= 2)
        return (n - 1);
    int a = 0, b = 1, c;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int testCases, n;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> n;
        cout << fibonacci(n) << endl;

        // your function
    }
}