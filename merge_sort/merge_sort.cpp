#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &A, vector<int> &tmp, int m,int l, int r) {
    int bi = l;
    int ci = m + 1;
    for(int i=l;i<=r;i++) {
        if (bi > m) {tmp[i] = A[ci++]; continue;}
        if (ci > r) {tmp[i] = A[bi++]; continue;}
        (A[bi] < A[ci]) ? tmp[i] = A[bi++]: tmp[i] = A[ci++];
    }
    for(int i=l;i<=r;i++) {
        A[i] = tmp[i];
    }
} 

void mergesort(vector<int> &A,vector<int> &tmp, int l, int r) {
    if (l >= r) return;
    int mid = (l+r) >> 1;
    mergesort(A,tmp ,l ,mid);
    mergesort(A,tmp ,mid+1 ,r);
    merge(A, tmp ,mid ,l , r);
}

void mergesort(vector<int> &A,int l, int r) {
    if (l >= r) return;
    vector<int> tmp(A.size());
    mergesort(A,tmp ,l ,r);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0;i<N;i++) cin >> arr[i];
    for (auto &x: arr) cout << x << ' ';
    cout << "\n";
    mergesort(arr, 0, arr.size()-1);
    for (auto &x: arr) cout << x << ' ';
}