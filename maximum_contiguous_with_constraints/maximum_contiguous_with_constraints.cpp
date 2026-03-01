#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int getSum(vector<int> &S,int start, int stop)  {
    if (start == 0) return S[stop];
    return S[stop] - S[start - 1];
}

int main() {
    int n,w,tmp = 0;
    cin >> n >> w;
    vector<int> arr(n), S(n);
    for (int i = 0;i<n;i++) {
        cin >> arr[i];
        tmp += arr[i];
        S[i] = tmp;
    }
    for (auto &x:S) cout << x << " ";
    deque<int> table; // table stores index of minimum prefix sum
    int ans = INT_MIN;
    for (int i = 0; i < n;i++) {
        while (!table.empty() && i - table.front() > w) table.pop_front();
        if (!table.empty()) ans = max(ans,getSum(S,table.front()+1,i));
        while (!table.empty() && getSum(S,0,table.back()) > getSum(S,0,i)) table.pop_back();
        table.push_back(i);
    }
    cout << ans;
}