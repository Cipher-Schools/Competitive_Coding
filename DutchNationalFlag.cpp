// Sort a binary array
// [0, 1, 1, 0, 1, 0, 0, 1]
// [0, 0, 0, 0, 1, 1, 1, 1]

// Sort an array with 0/1/2
// 0/1/2 [0, 2, 1, 2, 1, 2, 0, 0, 0]

//       [0, 0, 0, 0, 1, 1, 2, 2, 2]

// 1. Count O(2*n), O(1) | Unordered Map | Hash
// 3. Sorting Algorithm O(nlogn) O(space)
// 4. Two Pointer O(n)
// 5. Frequency O(n)

// int count0, count1, count2;
// 12B

// 12B >

#include <bits/stdc++.h>
using namespace std;

// void dutchNationalFlag(vector<int>& vec) {
//     int s = 0, e = vec.size() - 1;
//     while(s <= e) {
//         while (vec[s] == 0) {
//             s++;
//         }

//         while(vec[e] == 1) {
//             e--;
//         }

//         if (s <= e) {
//             swap(vec[s], vec[e]);
//             s++;
//             e--;
//         }
//     }
// }

void dutchNationalFlag(vector<int> &vec)
{
    int zp = 0, op = 0, tp = vec.size() - 1;
    while (op <= tp)
    {
        switch (vec[op])
        {
        case 0:
            swap(vec[zp], vec[op]);
            zp++;
            op++;
            break;
        case 1:
            op++;
            break;
        case 2:
            swap(vec[tp], vec[op]);
            tp--;
            break;
        default:
            break;
        }
    }
}

// ---------------------------------------------------------------- 
int main()
{
    vector<int> vec = {0, 1, 1, 2, 2, 2, 2, 2, 1, 1, 0, 0};
    dutchNationalFlag(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;

}


// // 2.5 -> 30 mins 
// 2 question => Medium
// 3 question => Easy 
// ~25 mins

// Introduction (2-5)
// 50 mins => 25 mins => 10 mins + 10 mins + 5 mins  
// Last 5 mins (Ask question from the interviewer)