#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#define ll long long
using namespace std;
ll ans = 0;
vector<ll> y;

ll solve(ll x,ll b, ll c) {
    ll tmp =0;
    auto itLower = lower_bound(y.begin(), y.end(), b);
    auto itUpper = upper_bound(y.begin(), y.end(), c);
    if (itLower == itUpper) return 0;
    tmp = itUpper - itLower;
    if (c-b < 2) {
        return tmp;
    }
    ll u = ((c-b+1)/3);
    ll v = ((c-b+2)/3);
    ll p1 = solve(x+1, b, b+u-1);
    ll p2 = solve(x+2, b+u, b+u+v-1);
    ll p3 = solve(x+3, b+u+v, c);
    return tmp + max({p1+p2,p2+p3,p1+p3});
}

int main() {
    int n;
    ll w;
    cin >> w >> n;
    for (int i =0;i<n;i++) {
        ll j;
        cin >> j;
        y.push_back(j);
    }
    sort(y.begin(), y.end());
    // for (auto &[k,v]:y) {
    //     cout << "i = " << k << " " << " v = " << v << "\n";
    // }
    cout << solve(0, 1, w);
}