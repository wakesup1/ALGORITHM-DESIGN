#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string A,B;
    cin >> A;
    cin >> B;
    if (A.size() < B.size()) swap(A, B);
    int dp[501][501];
    for (int l = 1; l <= B.size();l++) {
        for (int i = 1; i <= A.size();i++) {
            if (A[i-1] == B[l-1]) {
                dp[l][i] = dp[l-1][i-1] + 1;
            } else {
                dp[l][i] = max(dp[l-1][i],dp[l][i-1]);
            }
        }
    }
    for (int i = 0; i < B.size()+1;i++) {
        for (int j = 0; j<A.size()+1;j++) {
            cout << dp[i][j] << " ";
        }cout << "\n";
    }
    cout << dp[B.size()][A.size()];
}
