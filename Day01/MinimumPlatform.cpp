// Input: arr[] =  {9:00, 9:40, 9:50, 11:00, 15:00, 18:00} 
// dep[] =        {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 

// Task: Find the minimum number of platforms needed

// 9:00 --- 9:10 9:40 ---------------- 12:00
//                    9:50 -----11:20
//                            11:00--11:30 

// -----------------------------------------------------------
// Input: arr[] =  {9:00, 9:40, 9:50, 11:00, 15:00, 18:00} 
// dep[] =        {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 


// Find out the maximum number of passengers in the bus at any time 
#include <bits/stdc++.h>
using namespace std;

int minumumPlatform(const vector<int>& arr,const vector<int>& dept) {
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());
    int i = 1, j = 0;
    int currPlatform = 1, minPlatorm = 1;
    while (i < arr.size() && j < dept.size()) {
        if (arr[i] >= dept[j]) {
            // train 11:00 | dept 10:50
            currPlatform -= 1;
            j++;
        } else {
            // train 11:00 | dept 11:30
            currPlatform += 1;
            i++;
        }

        minPlatorm = max(minPlatorm, currPlatform);
    }

    return minPlatorm;
}
int main() {

    return 0;
}


int findMissing(vector<int> arr) {
    int missing = 0;
    for (int i = 0; i < arr.size(); i++) {
        missing = missing ^ (i + 1) ^ arr[i]; 
    }

    missing = missing ^ (arr.size() + 1);
}

