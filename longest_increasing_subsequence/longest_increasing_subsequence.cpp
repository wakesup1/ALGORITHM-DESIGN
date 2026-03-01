#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), dp(n,1);

    for (int i = 0; i< n;i++) cin >> arr[i];
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < i ;j++) {
            if (arr[j] < arr[i]) dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}