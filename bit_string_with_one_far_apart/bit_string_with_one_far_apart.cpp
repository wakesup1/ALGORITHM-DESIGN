#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp(5001);

int DP(int idx) {
    if (idx < 0) return 0;
    return dp[idx];
}

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < k;i++) dp[i] = i + 1;
    for (int i = k; i <= n;i++) {
        dp[i] = (dp[i-1] + DP(i-k))%100000007;
    }
    cout << dp[n];
    
}