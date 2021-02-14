#include <bits/stdc++.h>
using namespace std;

void generateBinaryBitsHelper(vector<string>& result, vector<int>& bitsSoFar, int index, int N) {
    if (index == N) {
        string str = "";
        for (int i  = 0; i < N; i++) {
            str += to_string(bitsSoFar[i]);
        }
        result.push_back(str);
        return;
    } 
    bitsSoFar[index] = 0;
    generateBinaryBitsHelper(result, bitsSoFar, index+1, N);

    bitsSoFar[index] = 1;
    generateBinaryBitsHelper(result, bitsSoFar, index+1, N);
}

vector<string> generateBinaryBits(int N) {
    vector<int> bitsSoFar(N, 0);
    vector<string> result;
    generateBinaryBitsHelper(result, bitsSoFar, 0, N);
    return result;
}

int main() {
    vector<string> result = generateBinaryBits(5);
    for (string str: result) {
        cout << str << endl;
    }
}