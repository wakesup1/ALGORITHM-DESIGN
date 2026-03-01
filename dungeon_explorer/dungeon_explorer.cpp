#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
    vector<vector<int>> A(r+1, vector<int>(c+1, 0));
    for (int i = 1; i <= r;i++) {
        for (int j = 1; j <= c;j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= r;i++) {
        for (int j = 1; j <= c;j++) {
            if (A[i][j] != -1) dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + A[i][j];
        }
    }
    // for (int i = 1; i <= r;i++) {
    //     for (int j = 1; j <= c;j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << "\n";
    // }
    cout << dp[r][c];
}