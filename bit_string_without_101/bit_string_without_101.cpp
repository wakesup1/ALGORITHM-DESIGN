#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 0) return 0;
    long long BASE_MOD = 100000007;
    // dp[length][last_state]
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));

    // Base case (ยาว 1)
    dp[1][0] = 1; // "0"
    dp[1][1] = 1; // "1"
    dp[1][2] = 0; // ไม่มี "10"

    for (long long i = 2; i <= n; i++) {
        // สร้าง State 0: จาก 0 เติม 0 หรือ จาก 2 เติม 0
        dp[i][0] = (dp[i-1][0] + dp[i-1][2])%BASE_MOD;
        
        // สร้าง State 1: จาก 0 เติม 1 หรือ จาก 1 เติม 1
        dp[i][1] = (dp[i-1][0] + dp[i-1][1])%BASE_MOD;
        
        // สร้าง State 2: จาก 1 เติม 0
        dp[i][2] = (dp[i-1][1])%BASE_MOD;
    }
    unsigned long long answer = (dp[n][0] + dp[n][1] + dp[n][2])%BASE_MOD;
    cout << answer << endl;
    return 0;
}