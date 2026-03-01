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
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n;i++) {
        dp[i] = (dp[i-1] + DP(i-k))%100000007;
    }
    cout << dp[n];
    
}