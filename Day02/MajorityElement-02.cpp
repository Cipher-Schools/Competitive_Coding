#include <bits/stdc++.h>
using namespace std;

// Using Moore's Voting Algoritm
int majorityElement(vector<int> &vec)
{
    int majElementIndex = 0, count = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[majElementIndex])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            majElementIndex = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == vec[majElementIndex])
        {
            count++;
        }
    }

    if (2 * count > vec.size())
    {
        return vec[majElementIndex];
    }
    else
    {
        return -1;
    }
}

int main()
{
    int testCases, vecSize;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> vecSize;
        vector<int> vec(vecSize);
        for (int i = 0; i < vec.size(); i++)
        {
            cin >> vec[i];
        }

        cout << majorityElement(vec) << "\n";
    }
}