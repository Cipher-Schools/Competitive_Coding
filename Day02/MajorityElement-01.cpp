#include <bits/stdc++.h>
using namespace std;

// Using Hashmap
int majorityElement(vector<int> &vec)
{
    map<int, int> hash;
    for (int i = 0; i < vec.size(); i++)
    {
        hash[vec[i]]++;
    }
    int majorityElement = -1, countSoFar = 0;
    for (auto itr = hash.begin(); itr != hash.end(); itr++)
    {
        if (itr->second > countSoFar)
        {
            majorityElement = itr->first;
            countSoFar = itr->second;
        }
    }

    if (2 * countSoFar > vec.size())
    {
        return majorityElement;
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