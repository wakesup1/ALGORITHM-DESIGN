#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp(4002, -1);

int DP(int idx) {
    if (idx < 0) return -1;
    else if (dp[idx] != -1) return dp[idx] + 1;
    return -1;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max({DP(i-a),DP(i-b),DP(i-c)});
    }
    for (int i = 1; i <= n;i++) {
        cout << dp[i] << ' ';
    }
    //cout << dp[n];
}
