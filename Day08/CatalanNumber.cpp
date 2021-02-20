#include <bits/stdc++.h>
using namespace std;

int catalanNumber(int N) {
    vector<long long> catalan(N+1);
    catalan[0] = catalan[1] = 1;

    for (int n = 2; n <= N; n++) {
        catalan[n] = 0;
        for (int j = 0; j < n; j++) {
            catalan[n] = catalan[j] * catalan[n - j - 1];
        }
    }
    return catalan[N];
}

int main() {

}