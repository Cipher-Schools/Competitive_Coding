#include <bits/stdc++.h>
using namespace std;

vector<int> *mergeSortedArrays(vector<int> &a, vector<int> &b)
{
    vector<int> *result = new vector<int>(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            result->at(k) = a[i];
            i++;
        }
        else
        {
            result->at(k) = b[j];
            j++;
        }
        k++;
    }

    while (i < a.size())
    {
        result->at(k) = a[i];
        i++; k++;
    }

    while (j < b.size())
    {
        result->at(k) = b[j];
        j++; k++;
    }
}

int main()
{
    int testCases, as, bs;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> as;
        vector<int> a(as);
        for (int i = 0; i < as; i++)
        {
            cin >> a[i];
        }

        cin >> bs;
        vector<int> b(bs);
        for (int j = 0; j < bs; j++)
        {
            cin >> b[j];
        }

        vector<int>* result = mergeSortedArrays(a, b);
        for (int i = 0; i < result->size(); i++) {
            cout << result->at(i) << " "; 
        }
        cout << endl;
    }
}