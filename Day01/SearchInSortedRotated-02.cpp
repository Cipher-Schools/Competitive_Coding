#include <bits/stdc++.h>
using namespace std;

int searchInSortedRotatedHelper(vector<int> &vec, int start, int end, int element)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (vec[mid] == element)
        return mid;

    if (vec[start] <= vec[mid])
    {
        // first segment is sorted
        if (element >= vec[start] && element <= vec[mid])
        {
            return searchInSortedRotatedHelper(vec, start, mid - 1, element);
        }
        else
        {
            return searchInSortedRotatedHelper(vec, mid + 1, end, element);
        }
    }
    else
    {
        // last segment is sorted
        if (element >= vec[mid] && element <= vec[end])
        {
            return searchInSortedRotatedHelper(vec, mid + 1, end, element);
        }
        else
        {
            return searchInSortedRotatedHelper(vec, start, mid - 1, element);
        }
    }
}

int searchInSortedRotated(vector<int> &vec, int element)
{
    return searchInSortedRotatedHelper(vec, 0, vec.size() - 1, element);
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
        cout << searchInSortedRotated(vec, element) << endl;
    }
}