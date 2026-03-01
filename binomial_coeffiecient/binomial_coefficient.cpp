#include <iostream>
using namespace std;
int dp[31][31];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[n][k];
}