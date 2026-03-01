#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeCount(vector<int> &arr, int start, int stop, int k, int &cnt) {
    if (stop - start <= 1) return;
    if (cnt >= k) return ;
    int mid = (start + stop) >> 1;
    swap(arr[mid-1],arr[mid]);
    cnt+=2;
    mergeCount(arr, start, mid, k, cnt);
    mergeCount(arr, mid, stop, k, cnt);
}

int main() {
    int n,k,cnt = 1;
    cin >> n >> k;
    if (k%2==0) {cout << "-1"; return 0;}
    vector<int> arr(n);
    for (int i = 1;i<=n;i++) arr[i-1] = i;
    mergeCount(arr, 0, arr.size(), k, cnt);
    if (cnt == k) for (int i = 1;i<=n;i++) cout << arr[i-1] << " ";
    else cout << '-1';
}
