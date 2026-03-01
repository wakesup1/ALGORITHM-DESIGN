#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
int n,k;
ll dp[10001];
using namespace std;
vector<int> S;
ll ans = 0;

int main() {
    cin >> n >> k;
    S.resize(k);
    for (int i =0;i<k;i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    dp[0] = 1;
    for (int i =1; i<=n;i++) {
        for (auto&x:S) {
            if (i-x>=0) dp[i] = (dp[i] + dp[i-x])%1000003;
        }
    }
    cout << dp[n];
}