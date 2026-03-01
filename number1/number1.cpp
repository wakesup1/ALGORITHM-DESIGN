#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(int n) {
    if (n == 1) return 1;
    return count(n/2) + 1 + count(n/2);
}

int cumulate(int n, int l, int r) {
    if (n == 1 || n == 0) return n;
    int tmp = 0;
    int left = count(n/2);
    int mid = left + 1;
    int right = mid + left;
    if (l < mid) {
        tmp += cumulate(n/2, l, r);
    }
    if (l <= mid && r >= mid) {
        tmp += n%2;
    }
    if (r > mid) {
        tmp += cumulate(n/2, l-mid,r-mid);
    }
    return tmp;
}

int main () {
    int n, l, r;
    cin >> n >> l >> r;
    cout << cumulate(n,l,r);
}
 
/*
    1 = 1
    2 = 1 0 1
    3 = 1 1 1
    4 = 1 0 1 0 1 0 1
    5 = 1 0 1 1 1 0 1
    6 = 1 1 1 0 1 1 1 [3] 0 [3]
    ex n = 9 => [4] [1] [4] (7) (1) (7)
    1,0,1,0,1,0,1,1,1,0,1,0,1,0,1

    ..... kk+1 ...... 2k+1
*/