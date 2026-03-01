#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll thanosPower(vector<ll> &arr, ll start, ll stop, ll B, ll A) {
    auto itStart = lower_bound(arr.begin(), arr.end(), start);
    auto itStop = upper_bound(arr.begin(), arr.end(), stop);

    if (start == stop) {
        if (itStop - itStart >= 1) {
            return B * (itStop - itStart);
        }
        return A;
    }

    
    ll mid = (start+stop) >> 1;
    ll leftPower = thanosPower(arr, start,mid,B,A);
    ll rightPower = thanosPower(arr, mid+1,stop,B,A);
    ll totalPower = 0, correction = A;
    bool hasAvenger = ((itStop - itStart) >= 1);

    totalPower = B * (itStop - itStart) * (stop - start + 1);

    if (hasAvenger) return min(totalPower, leftPower + rightPower); 
    else return min(totalPower + correction, leftPower + rightPower);
    
}

int main () {
    ll p,k,A,B,a;
    vector<ll> avengerPosition;
    cin >> p >> k >> A >> B;
    for (ll i=0;i<k;i++) {
        cin >> a;
        avengerPosition.push_back(a);
    }
    sort(avengerPosition.begin(), avengerPosition.end());
    cout << thanosPower(avengerPosition, 1, pow(2,p), B,A);
}