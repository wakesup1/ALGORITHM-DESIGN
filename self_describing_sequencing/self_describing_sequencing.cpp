#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sds() {
    vector<int> S = {0,1,3};
    int tmp = 3;
    while (S.back() < 2e9) {
        auto it = lower_bound(S.begin(), S.end(), tmp++);
        S.push_back(S.back() + (it - S.begin()));
    }
    return S;
}

int main() {

    int N,q;
    cin >> N;
    vector <int> S = sds(); 
    /*
    S is set that store S[i] that index i ends at where
    */
    for (auto &x : S) cout << x << " ";
    // while (N--) {
    //     cin >> q;
    //     cout << lower_bound(S.begin(), S.end(), q) - S.begin() << "\n";
    // }
}