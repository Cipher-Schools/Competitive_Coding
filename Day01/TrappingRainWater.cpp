#include <bits/stdc++.h>
using namespace std;


// int trappingRainWater(const vector<int> &vec)
// {
//     int size = vec.size();
//     vector<int> lMax(size), rMax(size);
//     lMax[0] = vec[0];
//     for (int i = 1; i < size; i++)
//     {
//         lMax[i] = max(lMax[i - 1], vec[i]);
//     }
//     rMax[size - 1] = vec[size - 1];
//     for (int j = size - 2; j >= 0; j--)
//     {
//         rMax[j] = max(rMax[j + 1], vec[j]);
//     }

//     int countWater = 0;
//     for (int i = 0; i < size; i++) {
//         countWater += (min(lMax[i], rMax[i]) - vec[i]);
//     }

//     return countWater;
// }


int trappingRainWater(const vector<int> &vec)
{
    int size = vec.size();
    vector<int> rMax(size);
    int lMax = vec[0];
    rMax[size - 1] = vec[size - 1];
    for (int j = size - 2; j >= 0; j--)
    {
        rMax[j] = max(rMax[j + 1], vec[j]);
    }

    int countWater = 0;
    for (int i = 0; i < size; i++) {
        lMax = max(lMax, vec[i]);
        countWater += (min(lMax, rMax[i]) - vec[i]);
    }

    return countWater;
}

int main()
{

    return 0;
}