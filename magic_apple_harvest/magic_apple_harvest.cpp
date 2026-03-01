#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int atA(int idx) {
    if (idx < 0) return 0;
    return A[idx];
}

int main() {
    int n;
    cin >> n;
    A.resize(n, 0);
    for (int i = 0; i < n;i++) cin >> A[i];
    vector<int> dp(n+3, 0);
    for (int i = 3; i <= n+2; i++) {
        dp[i] = max({dp[i-1], dp[i-2]+atA(i-3), dp[i-3] + atA(i-4) + atA(i-3)});
    }
    // for (int i = 3; i <= n+1; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dp[n+2];
}