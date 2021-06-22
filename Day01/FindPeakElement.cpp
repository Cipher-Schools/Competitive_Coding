#include <bits/stdc++.h>
using namespace std;

vector<int> *findPeakElement(const vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1)
        return NULL;

    vector<int> *result = new vector<int>();

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (vec[i] >= vec[i + 1]) {
                result->push_back(i);
            }
        }
        else if (i == n - 1)
        {
            if (vec[i - 1] <= vec[i]) {
                result->push_back(i);
            }
        }
        else
        {
            if (vec[i-1] <= vec[i] && vec[i] >= vec[i + 1]) {
                result->push_back(i);
            }
        }
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

        vector<int> *result = findPeakElement(vec);
        if (result == NULL)
        {
            cout << "No Peak Element\n";
        }
        else
        {
            for (int i = 0; i < result->size(); i++)
            {
                cout << vec[result->at(i)] << " ";
            }
            cout << endl;
        }
    }
}