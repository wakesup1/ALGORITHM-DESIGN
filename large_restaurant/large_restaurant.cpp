#include <iostream>
#include <vector> 
#include <algorithm>

typedef long long ll;
using namespace std;

ll findTime(ll c, vector<int> &T) {
    if (c <= T.size()) return 0;
    ll left = 0;
    ll ans = 0;
    ll right = 2e15;
    while (left <= right) {
        ll totalCustomer = 0;
        ll mid = (left + right)/2;
        for (auto &x:T) {
            totalCustomer += ((mid / x) + 1);
        }
        if (totalCustomer >= c) {
            ans = mid;
            right = mid - 1;
            
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,A;
    cin >> N >> A;
    vector<int> T(N);
    ll c;
    for (int i = 0;i<N;i++) {
        cin >> T[i];
    }
    for (int i = 0;i<A;i++) {
        cin >> c;
        cout << findTime(c, T) << "\n";
    }
}