#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void gaa(vector<ll> S, int k, int n) {
    if (k == 0) {
        if (n == 1) {cout << "g"; return;}
        cout << "a"; return;
    }
    ll left = S[k-1];
    ll mid = k+3;
    ll right = left + mid;
    if (n > left && n <= right) {
        if (n == left + 1) {cout << "g"; return;}
        cout << "a"; return;
    } 

    if (n <= left) {
        gaa(S, k-1, n);
    }

    if (n > right) {
        gaa(S, k-1, n - right);
    }
}

int main(){
    ll n;
    vector<ll> S;
    cin >> n;
    S.push_back(3);
    int k = 0;
    while (S[k] < n) {
        S.push_back(2*S[k] + (k+1) + 3);
        k += 1;
    }
    //for (auto &x:S) cout << x << " ";
    gaa(S,k,n);
}