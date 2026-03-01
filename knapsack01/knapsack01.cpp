#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501][501];
int v[501];
int w[501];
int main() {
    int N, m;
    cin >> N >> m;
    vector<int> ans;
    for (int i =0;i<N;i++) {
        cin >> v[i];
    }
    for (int i =0;i<N;i++) {
        cin >> w[i];
    }
    for (int i =0;i<N+1;i++) {
        for (int j = 0; j < m+1;j++) {
            cin >> dp[i][j];
        }
    }
    int b = m;
    for (int i = N; i > 0;i--) {
        if (dp[i][b] == 0) {
            break;
        }
        if (dp[i][b] == dp[i-1][b]) {
            continue;
        } else {
            ans.push_back(i);
            b = b - w[i-1];
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (auto &x:ans) {
        cout << x << " ";
    }
}