#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(1000002,0);
int n, k;

int main() {
    cin >> n >> k;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i <= k;i++) {
        cin >> dp[i];
    }
    for (int i = k+1; i <= n;i++) {
        int p,b, tmp = 0;
        cin >> p;
        while(p--) {
            cin >> b;
            tmp = (tmp + dp[(i - b >= 0 ? i - b: 0)])%32717;
        } 
        dp[i] = tmp;
    }
    for (int i = 1; i<=n;i++) cout << dp[i] << " ";
}