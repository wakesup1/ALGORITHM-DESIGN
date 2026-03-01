#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

vector<int> sumSubArr(vector<int> &arr) {
    vector<int> S(arr.size());
    int tmp = 0;
    for (int i = 0;i<arr.size();i++) {
        tmp += arr[i];
        S[i] = tmp;
    }
    return S;
}

int getSum(int start, int stop,vector<int> &S) {
    if (start == 0) return S[stop - 1];
    return S[stop - 1] - S[start - 1];
    // [0,2) => arr[0] + arr[1] = S[1] 
    // [3,6) => arr[3] + arr[4] + arr[5] = S[5] - S[2]
    }

int maximumSubArr(vector<int> &arr, int start, int stop,vector<int> &S) {
    if (stop - start == 1) return arr[start];
    int mid = (start + stop) >> 1;

    int r1 = maximumSubArr(arr, start, mid, S);
    int r2 = maximumSubArr(arr, mid, stop, S);

    int leftMaximum = getSum(mid-1, mid, S); 
    int leftMinimum = getSum(mid-1, mid, S); 
    for (int i = start;i<mid;i++) {
        leftMaximum = max(leftMaximum, getSum(i, mid, S));
        leftMinimum = min(leftMinimum, getSum(i, mid, S));
    }

    int rightMaximum = getSum(mid, mid, S);
    int rightMinimum = getSum(mid, mid, S);
    for (int i = mid;i<stop;i++) {
        rightMaximum = max(rightMaximum, getSum(mid, i, S));
        rightMinimum = min(rightMinimum, getSum(mid, i, S));
    }

    int r3 = leftMaximum + rightMaximum;
    int r4 = S[arr.size() - 1] - (rightMinimum + leftMinimum);
    vector<int> v = {r1,r2,r3,r4};
    return *max_element(v.begin(), v.end());
}

int main() {
    int n,a;
    cin >> n;
    vector <int> arr(n);
    for (int i =0;i<n;i++) {
        cin >> a;
        arr[i] = a;
    }
    vector<int> S = sumSubArr(arr);
    cout << maximumSubArr(arr, 0, arr.size(), S);
}