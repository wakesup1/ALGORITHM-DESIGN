#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<vector<int>> arr;
int ans = INT_MIN;
int n;
void cal(int r, int c) {
    int best = 0;
    for (int i = 0; i < arr.size();i++) {
        if (r+i >= arr.size() || c+i >= arr.size())break;
        best = max(arr[r+i][c+i],best + arr[r+i][c+i]);
        ans = max(ans, best);
    }
}

int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n;i++) {
        arr[i].resize(n);
        for (int j = 0; j < n;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i<n;i++) {
        if (i==0) {cal(0,0); continue;}
        cal(0, i);
        cal(i, 0);
    }
    cout << ans;
}