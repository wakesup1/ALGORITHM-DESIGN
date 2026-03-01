#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
vector<ll> one;

int qk(ll n) {
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 3;
    if (n==4) return 4;
    if (n==5) return 5;
    if (n==6) return 6;
    if (n==7) return 6;
    if (n==8) return 5;
    if (n==9) return 4;
    if (n==10) return 3;
    if (n==11) return 2;
    auto it1 = lower_bound(one.begin(), one.end(),n);
    auto it2 = prev(it1);
    ll diff1 = abs(*it1 - n);
    ll diff2 = abs(*it2 - n);
    
    ll ans1 = LLONG_MAX;
    ll ans2 = LLONG_MAX;
    if (diff1 < n) ans1 = (it1 - one.begin() + 1) + qk(diff1);
    if (diff2 < n) ans2 = (it2 - one.begin() + 1) + qk(diff2);
    return min(ans1,ans2);
}

int main() {
    int n;
    cin >> n;
    one.push_back(1);
    for (int i = 1; i<12;i++) {
        one.push_back(one[i-1] + pow(10,i));
    }
    cout << qk(n);
}