#include <bits/stdc++.h>
using namespace std;

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

int findPivot(vector<int> &vec)
{
    return findPivotHelper(vec, 0, vec.size() - 1);
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
        cout << findPivot(vec) << endl;
    }
}