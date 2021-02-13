#include <bits/stdc++.h>
using namespace std;

int getCandidateIndex(vector<int>& vec) {
    int candidateIndex = 0, count = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[candidateIndex]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidateIndex = i;
            count = 1;
        }
    }
    return candidateIndex;
}

int findMajority(vector<int>& vec) {
    int candidateIndex = getCandidateIndex(vec);

    int freq = 0;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == vec[candidateIndex]) {
            freq++;
        }
    }

    if (freq > vec.size()/2){
        cout << vec[candidateIndex] << " ";
    } else {
        cout << "No candidateIndex found" << endl;
    }
}

int main() {
    vector<int> vec = {1, 1, 3, 2, 1, 1, 1, 5, 6, 7};
    return 0;
}