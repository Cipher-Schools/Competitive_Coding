#include <bits/stdc++.h>
using namespace std;

// No Swapping. Using a two pointer approach
void segregate0s1s(vector<int> &vec) {
    int start = 0, end = vec.size() - 1;
    while (start < end) {
        while (start < end && vec[start] == 0) start ++;

        while (start < end && vec[end] == 1) end--;

        if (start < end) {
            vec[start] = 0; start++;
            vec[end] = 1; end--; 
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