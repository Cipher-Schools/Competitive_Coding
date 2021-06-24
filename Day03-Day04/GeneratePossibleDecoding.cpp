#include <bits/stdc++.h>
using namespace std;

// string decoder = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ"

vector<char> decoder = {'_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void generateAllPossibleDecodingsHelper(const string &number, int index, string &decodingSoFar, vector<string> &possibleDecodings)
{
    if (index >= number.size())
    {
        possibleDecodings.push_back(decodingSoFar);
        return;
    }

    int digit = int(number[index] - '0');
    if (digit == 0) return;

    decodingSoFar.push_back(decoder[digit]);
    generateAllPossibleDecodingsHelper(number, index + 1, decodingSoFar, possibleDecodings);
    decodingSoFar.pop_back();

    if (index + 1 < number.size())
    {
        int digit2 = int(number[index + 1] - '0');
        if (digit * 10 + digit2 < decoder.size())
        {
            decodingSoFar.push_back(decoder[digit * 10 + digit2]);
            generateAllPossibleDecodingsHelper(number, index + 2, decodingSoFar, possibleDecodings);
            decodingSoFar.pop_back();
        }
    }
}

vector<string> generateAllPossibleDecodings(const string &number)
{
    vector<string> possibleDecodings;
    string decodingSoFar = "";
    generateAllPossibleDecodingsHelper(number, 0, decodingSoFar, possibleDecodings);
    return possibleDecodings;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        string number;
        cin >> number;
        vector<string> possibleDecodings = generateAllPossibleDecodings(number);
        for (string possibleDec : possibleDecodings)
        {
            cout << possibleDec << " ";
        }
        cout << endl;
        // your function
    }
}