#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> B;
vector<int> arr;

int main() {
    int n;
    cin >> n; arr.resize(n); B.resize(n);
    if (n==2) {
        int a, b;
        cin >> a >> b;
        cout << max({a,b,a+b});
        return 0;
    }
    for (int i =0;i<n;i++) {
        cin >> arr[i];
    }
    B[0] = arr[0]; B[1] = arr[0] + arr[1]; B[2] = max(B[0],B[1]) + arr[2];
    for (int i =3;i<n;i++) {
        B[i] = max({B[i-1], B[i-2], B[i-3]}) + arr[i];
    }
    cout << B[n-1];
}