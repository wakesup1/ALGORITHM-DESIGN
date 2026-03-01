#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr(5000);
vector<vector<int>> dp(5000, vector<int> (5000, 0));

int atArr(int idx) {
    if (idx < 0) return 0;
    return arr[idx];
}

int atDP(int idxI, int idxJ) {
    if (idxI < 0 || idxJ < 0) return 0;
    return dp[idxI][idxJ];
}

int main() {
    int n;
    cin >>n;
    
    for (int i = 0; i < n;i++) cin >> arr[i];
    for (int i = 0; i < n-1;i++) {
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }
    
    for(int len = 4; len <= n;len+=2) {
        for (int i = 0; i + len <= n;i++) {
            int j = i + len - 1;
            int opt1 = max(arr[i], arr[i+1]) + dp[i+2][j];
            int opt2 = max(arr[j], arr[j-1]) + dp[i][j-2];
            int opt3 = max(arr[i], arr[j]) + dp[i+1][j-1];

            dp[i][j] = max({opt1, opt2, opt3});
        }
    }
    cout << dp[0][n-1];
}