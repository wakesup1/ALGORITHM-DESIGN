#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool differCheck(vector<int> &v1, vector<int> &v2) {
    int c1 = 0, c2 = 0;
    for (int i = 0 ;i < v1.size(); i++) {
        if (v1[i] == 1) c1 ++;
        if (v2[i] == 1) c2 ++;
    }
    return std::abs(c1-c2) <= 1;
}

bool isVirus(vector<int> arr) {
    if (arr.size() == 2) {
        return true;
    }
    int mid = (arr.size())/2;
    vector<int> halfLeft(arr.begin(), arr.begin() + mid);
    vector<int> halfRight(arr.begin() + mid, arr.end());
    return differCheck(halfLeft, halfRight) && isVirus(halfLeft) && isVirus(halfRight);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(pow(2,k));
    for (int i = 0; i<n;i++) {
        for (int j =0 ; j<arr.size();j++){
            cin >> arr[j];
        }
        cout << (isVirus(arr) ? "yes\n":"no\n") ;
    }
}