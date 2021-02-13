#include <bits/stdc++.h>
using namespace std;
// [4, -5, 1, 8, 19, -30]
// Homework: Print the subarray by using si and ei
int largestContiguousArraySum(vector<int> vec) {
    int cs = vec[0], ms = vec[0];
    int si = 0, msi = 0;

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > vec[i] + cs) {
            // vec[i] = 15 , cs = -13
            cs = vec[i];
            si = i;
        } else {
            // vec[i] = 2, cs = 1
            cs = vec[i] + cs;
        }

        if (cs >= ms) {
            ms = cs;
            msi = si;
        }
    }

    return ms;
}
int main(){
    return 0;
}