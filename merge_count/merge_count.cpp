#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate(vector<int> &A,int l, int r,int k, int &cnt) {
    if (r-l < 1) return;
    if (cnt >= k) return;
    int mid = (l+r) >> 1;
    swap(A[mid-1], A[mid]);
    cnt+=2;
    generate(A,l,mid, k, cnt);
    generate(A,mid,r, k, cnt);
}

int main() {
    int N, k, cnt = 1;
    cin >> N >> k;
    if (k%2==0 || k > (2*N -1)) {cout << "-1"; return 0;}
    vector<int> arr(N);
    for (int i = 0;i<N;i++) arr[i] = i+1;
    generate(arr, 0, N, k, cnt);
    if (cnt != k) {cout << "-1"; return 0;}
    for (auto &x: arr) cout << x << ' ';
}