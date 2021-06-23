#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFirstAndLastOccurrence(const vector<int> &vec, int x)
{
    // Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
    // In other words, it'll point to the first element greater than or equal to the given element.
    // if that element is not found,
    // 1. if x < vec[0] it'll return vec.begin(),
    // 2. If x > vec[vec.size() - 1], it'll return vec.end()
    auto firstOccurrence = lower_bound(vec.begin(), vec.end(), x);

    // Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
    // In other words, it'll point to the first element greater than the given element.
    // if that element is not found,
    // 1. if x < vec[0] it'll return vec.begin(),
    // 2. If x > vec[vec.size() - 1], it'll return vec.end()
    auto lastOccurrence = upper_bound(vec.begin(), vec.end(), x);

    if (firstOccurrence == vec.end()) {
        return {-1, -1};
    } else {
        return {firstOccurrence - vec.begin(), lastOccurrence - vec.begin() - 1};
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

        pair<int, int> p = findFirstAndLastOccurrence(vec, element);
        cout << p.first << " " << p.second << endl;
    }
}