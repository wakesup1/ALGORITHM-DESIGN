#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for (int i = 0; i <= n;i++) cin >> arr[i];
    
    for (int i = n; i >= 1;i--) {
        for (int j = i+1; j <= n;j++) {
            int tmp = 1e9;
            for (int k = i; k < j; k++) {
                tmp = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j], tmp);
            }
            dp[i][j] = tmp;
        }
    }
    for (int i = 0; i <= n;i++) {
        for(int j = 0;j<=n;j++) {
            cout << dp[i][j] << ' ';
        } cout << "\n";
    }
}