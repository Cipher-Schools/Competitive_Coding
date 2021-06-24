#include <bits/stdc++.h>
using namespace std;

void generateBinaryBitsHelper(vector<string> &result, string &bitsSoFar, int index, int N)
{
    if (index == N)
    {
        result.push_back(bitsSoFar);
        return;
    }
    bitsSoFar[index] = '0';
    generateBinaryBitsHelper(result, bitsSoFar, index + 1, N);

    bitsSoFar[index] = '1';
    generateBinaryBitsHelper(result, bitsSoFar, index + 1, N);
    bitsSoFar[index] = '.';
}

vector<string> generateBinaryBits(int N)
{
    vector<string> result;
    string bitsSoFar(N, '.');
    generateBinaryBitsHelper(result, bitsSoFar, 0, N);
    return result;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        int number;
        cin >> number;
        vector<string> allBinaryBits = generateBinaryBits(number);
        for (string possible : allBinaryBits)
        {
            cout << possible << " ";
        }
        cout << endl;
        // your function
    }
}