#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int getSum(vector<int> &S, int start, int stop) {
    if (start == 0) return S[stop];
    return S[stop] - S[start-1];
}

int main() {
    int n,a;
    int localMax = INT_MIN;
    cin >> n;
    vector<int> arr(n),S(n);
    map<int,vector<int>> table;
    int tmp = 0;
    for (int i =0;i<n;i++) {
        cin >> a;
        arr[i] = a;
        if (a > localMax) localMax = a;
        tmp+=a;
        S[i] = tmp;
        table[a].push_back(S[i]);
    }

    for (auto &[k,v]: table) {
        if (v.size() > 1){
            int bestMax = 0;
            int leftMin = v[0];
            for (int i = 1; i < v.size();i++) {
                bestMax = max(bestMax, v[i] - leftMin);
                leftMin = min(leftMin, v[i]);
            }
            localMax = max(localMax, bestMax + k);
        } 
    }
    cout << localMax;
}