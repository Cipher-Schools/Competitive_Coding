#include <bits/stdc++.h>
using namespace std;

// count 0s and 1s in one loop and then set 0s and 1s
void segregate0s1s(vector<int> &vec) {
    int count0 = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) count0++;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (count0 > 0) {
            vec[i] = 0;
            count0--;
        } else {
            vec[i] = 1;
        }
    }
}

int main() {
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

        segregate0s1s(vec);

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}