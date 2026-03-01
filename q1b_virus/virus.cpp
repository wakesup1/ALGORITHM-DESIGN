#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(vector<int> arr) {
    if (arr.size() == 2) return arr[0] == 0 && arr[1] == 1;
    int mid = (arr.size())/2;
    vector<int> halfLeft(arr.begin(), arr.begin()+mid);
    vector<int> halfRight(arr.begin() + mid, arr.end());
    vector<int> halfLeftReverse(arr.rbegin()+mid, arr.rend());
    return (check(halfLeft) || check(halfLeftReverse)) && check(halfRight);
}

int main() {
    int n, k ;
    cin >> n >> k;
    vector<int> arr(pow(2,k));
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<pow(2,k);j++) {
            cin >> arr[j];
        }
        cout << (check(arr) ? "yes\n" : "no\n"); 
    }
}