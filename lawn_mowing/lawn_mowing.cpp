#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;
ll lawnMaximum(vector<ll> &arr,vector<ll> &S, ll start, ll costHold, ll k) {
    auto it = upper_bound(S.begin() + start, S.end(), S[start-1] + costHold);
    if (it != S.end()) {
        it--;
        ll idx = it - S.begin();
        // cout << "idx = " << idx << "\n";
        // cout << "S[idx] = " << S[idx] << "\n";
    

        return (S[idx] - S[start-1]) - (idx-start+1)*k;
    }
    return (S[S.size()-1] - S[start-1]) - (S.size() - start)*k;
}

int main() {
    ll n,m,k;
    ll a, b;
    cin >> n >> m >> k;
    vector<ll> arr(n), S(n+1); S[0] = 0;
    for (ll i = 1;i <= n;i++) {
        cin >> arr[i-1];
        S[i] = S[i-1] + arr[i-1] + k;
    }
    cout<<"\n";
    while (m--) {
        cin >> a >> b;
        cout << lawnMaximum(arr, S, a+1, b, k) << "\n";
    }
}