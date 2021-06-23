#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(const vector<int> &vec, int x)
{
    int start = 0, end = vec.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (vec[mid] > x) {
            end = mid - 1;
        } else if (vec[mid] < x) {
            start = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(const vector<int> &vec, int x)
{
    int start = 0, end = vec.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (vec[mid] > x) {
            end = mid - 1;
        } else if (vec[mid] < x) {
            start = mid + 1;
        } else {
            result = mid;
            start = mid + 1;
        }
    }
    return result;
}

pair<int, int> findFirstAndLastOccurrence(const vector<int> &vec, int x)
{
    // sort(vec.begin(), vec.end())
    // If array is sorted, we don't need to sort it. Instead we'll try a linear approach
    int firstOccurrence = findFirstOccurrence(vec, x);
    int lastOccurrence = findLastOccurrence(vec, x);
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