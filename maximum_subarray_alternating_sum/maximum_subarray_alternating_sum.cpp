#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

long long maxArr(vector<long long> &arr,vector<long long> &S, int start, int stop) {
    long long bestMax = 0;
    long long ansMax = arr[start];
    for (int i = 0; i < S.size(); i += 2) {
        bestMax = max({S[i],bestMax+S[i]});
        ansMax = max({ansMax, bestMax, bestMax + (i+2>=arr.size()?0:arr[i+2])});
    }
    long long bestMaxN = 0;
    long long ansMaxN = arr[start+1];
    for (int i = 1; i < S.size(); i += 2) {
        bestMaxN = max({S[i],bestMaxN+S[i]});
        ansMaxN = max({ansMaxN, bestMaxN, bestMaxN + (i+2>=arr.size()?0:arr[i+2])});
    }
    return max(ansMax, ansMaxN);   
}

int main() {
    int n;
    long long a, tmpMax = INT_MIN;
    cin >> n;
    vector<long long> arr(n), S(n-1) ;
    for (int i=0;i<n;i++) {
        cin >> a;
        tmpMax = max(a,tmpMax);
        arr[i] = a;
    }
    if (arr.size() == 1) {cout <<  arr[0]; return 0;}
    for (int i=0;i<n-1;i++) {
        S[i] = arr[i] - arr[i+1];
    }
    for (auto&x:S) cout << x << " ";
    cout << max(tmpMax,maxArr(arr, S, 0, arr.size()));
}
// 0 2 4 6 8 
  // 01 [2] 23 [4] 45 [6] 67 [8] 89 [10]
// 1 3 5 7 9 
  // 12 [3] 34 [5] 56 [7] 78 [9] 910 [11]