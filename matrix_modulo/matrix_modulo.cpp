#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k) {
    vector<int> result(M);
    int am = M[0], bm = M[1], cm = M[2], dm = M[3];
    int an = N[0], bn = N[1], cn = N[2], dn = N[3];
    result[0] = (am%k * an%k + bm%k * cn%k) % k;
    result[1] = (am%k * bn%k + bm%k * dn%k) % k ;
    result[2] = (an%k * cm%k + cn%k * dm%k) % k;
    result[3] = (bn%k * cm%k + dm%k * dn%k) % k;
    return result;
}

vector<int> power(vector<int> arr, ll n,ll k) {
    if (n==1) return arr;
    vector<int> half = power(arr, n/2, k);
    vector<int> res = matrix_multiply(half,half,k);
    if (n%2==1) {
        res = matrix_multiply(res,arr,k);
    }
    return res;
}

int main() {
    vector<int> arr(4);
    ll n,k;
    cin >> n >> k;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    arr = {a,b,c,d};
    vector<int> res = power(arr,n,k);
    for (auto x: res) cout << x << " ";
}

/*
    a b | a b ==> aa + bc    ab + bd
    c d | c d ==> ac + cd    bc + dd

    return | (a%k * a%k + b%k * c%k) % k    (a%k * b%k + b%k * d%k) % k |
           | (a%k * c%k + c%k * d%k) % k    (b%k * c%k + d%k * d%k) % k |

    1 -> 2 -> 4 -> 8 -> 16 -> 32
*/