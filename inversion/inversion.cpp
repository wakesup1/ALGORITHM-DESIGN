#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int counter_pairs(vector<int> &v) {
    int count = 0;
    for (int i = 0; i < v.size();i++) {
        for (int j = i;j<v.size();j++) {
            if (v[i] > v[j]) count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int>A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    cout << counter_pairs(A);
}