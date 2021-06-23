#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(const vector<int> &vec, int start, int end, int x)
{
    // Edge case
    if (start > end)
    {
        return -1;
    }

    // base condition
    int mid = start + (end - start) / 2;
    if ((mid == 0 || x > vec[mid - 1]) && vec[mid] == x)
    {
        return mid;
    }
    // recursive condition
    else if (x <= vec[mid])
    {
        return findFirstOccurrence(vec, start, mid - 1, x);
    }
    else
    {
        return findFirstOccurrence(vec, mid + 1, end, x);
    }
}

int findLastOccurrence(const vector<int> &vec, int start, int end, int x)
{
    // Edge case
    if (start > end)
    {
        return -1;
    }

    // base condition
    int mid = start + (end - start) / 2;
    if ((mid == (vec.size() - 1) || x < vec[mid + 1]) && vec[mid] == x)
    {
        return mid;
    }
    // recursive condition
    else if (x < vec[mid])
    {
        // this condition can happen if x < vec[mid] 
        // which means that the first occurrence will be in the first segmnet (start, mid - 1)
        return findLastOccurrence(vec, start, mid - 1, x);
    }
    else
    {
        // this condition can happen when 
        // 1. x == vec[mid] (it is one occurence but not the last occurrence) 
        // 2. x > vec[mid] which means the first occurrence is in last segmnet (mid+1, end) 
        return findLastOccurrence(vec, mid + 1, end, x);
    }
}

pair<int, int> findFirstAndLastOccurrence(const vector<int> &vec, int x)
{
    // sort(vec.begin(), vec.end())
    // If array is sorted, we don't need to sort it. Instead we'll try a linear approach
    int firstOccurrence = findFirstOccurrence(vec, 0, vec.size() - 1, x);
    int lastOccurrence = findLastOccurrence(vec, 0, vec.size() - 1, x);
    return {firstOccurrence, lastOccurrence};
}

int main()
{
    int testCases, vecSize, element;
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
        cin >> element;

        pair<int, int> p = findFirstAndLastOccurrence(vec, element);
        cout << p.first << " " << p.second << endl;
    }
}