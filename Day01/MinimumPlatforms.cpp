#include <bits/stdc++.h>
using namespace std;

int minimumPlatforms(vector<int> arrival, vector<int> departure) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int minPlatform = 0, resultSoFar = 0, i = 0, j = 0;
    while (i < arrival.size() && j < departure.size()) {
        if (arrival[i] <= departure[j]) {
            i++;
            minPlatform ++;
        } else {
            j++;
            minPlatform--;
        }
        resultSoFar = max(minPlatform, resultSoFar);
    }
    return resultSoFar;
}
int main() {
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

        bs = as;
        vector<int> b(bs);
        for (int j = 0; j < bs; j++)
        {
            cin >> b[j];
        }

        cout <<  minimumPlatforms(a, b) << endl;
    }
}