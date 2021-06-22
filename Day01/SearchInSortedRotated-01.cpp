#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &vec, int start, int end, int element)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (element == vec[mid])
        return mid;
    else if (element < vec[mid])
    {
        return binarySearch(vec, start, mid - 1, element);
    }
    else
    {
        return binarySearch(vec, mid + 1, end, element);
    }
}

int findPivotHelper(vector<int> &vec, int start, int end)
{
    if (start > end)
        return -1;
    if (start == end)
        return start;
    int mid = start + (end - start) / 2;

    if (start < mid && vec[mid - 1] > vec[mid])
        return mid;
    if (mid < end && vec[mid] > vec[mid + 1])
        return mid + 1;

    if (vec[start] >= vec[mid])
    {
        // last segment is sorted
        return findPivotHelper(vec, start, mid - 1);
    }
    else
    {
        // first segment is sorted
        return findPivotHelper(vec, mid + 1, end);
    }
}

int searchInSortedRotated(vector<int> &vec, int element)
{
    int pivot = findPivotHelper(vec, 0, vec.size() - 1);
    if (pivot == -1)
    {
        // list is sorted
        return binarySearch(vec, 0, vec.size() - 1, element);
    }

    int result = binarySearch(vec, 0, pivot - 1, element);
    if (result == -1)
    {
        return binarySearch(vec, pivot, vec.size() - 1, element);
    }
    else
    {
        return result;
    }
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