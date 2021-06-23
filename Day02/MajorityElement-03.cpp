#include <bits/stdc++.h>
using namespace std;

// Using Sorting
int majorityElement(vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    int majElement = vec[0], countSoFar = 1, count = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > countSoFar)
        {
            majElement = vec[i];
            countSoFar = count;
        }
    }

    if (2 * countSoFar > vec.size())
    {
        return majElement;
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