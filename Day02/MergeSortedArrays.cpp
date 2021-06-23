#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> a, vector<int> b)
{
    vector<int> result(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            result[i] = a[i];
            i++;
        }
        else
        {
            result[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < a.size())
    {
        result[i] = a[i];
        i++;
        k++;
    }

    while (j < b.size())
    {
        result[k] = b[j];
        j++;
        k++;
    }

    return result;
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

        // your function
    }
}