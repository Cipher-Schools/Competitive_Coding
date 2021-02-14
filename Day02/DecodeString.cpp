#include <bits/stdc++.h>
using namespace std;

vector<string> mymap = {"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
void decodeStringHelper(vector<string>& result, string& digits, int index, string strSoFar) {
    if (index >= digits.size()) {
        result.push_back(strSoFar);
        return;
    }
    int idx1 = int(digits[index] - '0');
    if (idx1 == 0) {
        return;
    }
    decodeStringHelper(result, digits, index+1, strSoFar + mymap[idx1]);

    if (index + 1 >= digits.size()) {
        return;
    }

    int idx2 = int(digits[index + 1] - '0');
    if (10*idx1 + idx2 <= 26)
        decodeStringHelper(result, digits, index+2, strSoFar + mymap[10*idx1 + idx2]);
}
vector<string> decodeString(string& digits) {
    if (digits == "") {
        return vector<string>{};
    }
    vector<string> result;
    decodeStringHelper(result, digits, 0, "");
    return result; 

}
int main() {
    string decode = "20"; // 0xqndvcnbwe
    vector<string> result = decodeString(decode);
    for (string valid: result) {
        cout << valid << "\n";
    }
}