#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    vector<int> dp(m+1, 1e9);
    for (int i = 0;i<n;i++) {
        cin >> c[i];
    }
    dp[0] = 0;
    for (int i = 1;i<=m;i++) {
        for (auto &x:c) {
            if (i >= x) dp[i] = min(dp[i-x]+1,dp[i]);
            else dp[i] = 1e9;
        }
    }
    for (auto &x:dp) {
        cout << x << " ";   
    }
}