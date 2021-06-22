#include <bits/stdc++.h>
using namespace std;

void sort0s1s2s(vector<int> &vec) {
    int zp = 0, op = 0, tp = vec.size() - 1;
    while (op <= tp) {
        switch (vec[op]) {
            case 0: 
                swap(vec[zp], vec[op]);
                zp++; op++; break;
            case 1: 
                op++; break;
            case 2: 
                swap(vec[op], vec[tp]);
                tp--; break;
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
        
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        
        sort0s1s2s(vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}