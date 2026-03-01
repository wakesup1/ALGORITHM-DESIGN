#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int preS(vector<int>&S,int start, int stop) {
    if (start<=0) return S[stop];
    return S[stop] - S[start-1];
}

int main() {
    int n,a;
    cin >> n;
    vector<int> S(n);
    int tmp = 0;
    for (int i = 0; i<n;i++) {
        cin >> a;
        tmp += a;
        S[i] = tmp;
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n - 1;i++) {
        dp[i][i+1] = preS(S, i, i+1);
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n;i++) {
            int j = i + len - 1;
            int tmp = 1e9;
            for (int k = i; k < j;k++) {
                tmp = min(tmp, dp[i][k] + dp[k+1][j] + preS(S,i, j));
            }
            dp[i][j] = tmp;
        }
    }
    // for (int i = 0; i <= n;i++) {
    //     for (int j = 0; j <= n;j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << "\n";
    // }
    cout << dp[0][n-1];
}