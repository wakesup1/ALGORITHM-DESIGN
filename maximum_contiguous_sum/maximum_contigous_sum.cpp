#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maximumCrossing(vector<int> &arr, int start, int stop) {
    int leftMaximum = INT_MIN, rightMaximum = INT_MIN;
    int sum = 0;
    int mid = (start + stop) >> 1;

    for (int i = mid - 1; i >= start;i--) {
        sum += arr[i];
        if (sum > leftMaximum) leftMaximum = sum;
    }
    sum = 0;
    for (int i = mid; i < stop;i++) {
        sum += arr[i];
        if (sum > rightMaximum) rightMaximum = sum;
    }
    return rightMaximum + leftMaximum;
}

int maximumSubArr(vector<int> &arr, int start, int stop) {
    if (stop - start == 1) return arr[start];

    int mid = (start + stop) >> 1;

    return max({
        maximumSubArr(arr,start, mid),
        maximumSubArr(arr,mid,stop),
        maximumCrossing(arr, start, stop)
    });
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    cout << maximumSubArr(arr,0,arr.size());
}