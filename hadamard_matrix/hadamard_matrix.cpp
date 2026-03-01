#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hadamard(vector<int> v,int n) {
    vector<int> tmp;
    if (n==1) {
        tmp.push_back(v[0]);
        return tmp;
    }

    int midY = n/2;

    vector<int> vtop(midY),vbottom(midY);

    for (int i =0;i<v.size();i++) {
        if (i < midY) vtop[i] = v[i];
        if (i >= midY) vbottom[i -  midY] = v[i];
    }

    vector<int> vplus(midY); for (int i = 0;i<midY;i++) vplus[i] = vtop[i] + vbottom[i];
    vector<int> vminus(midY); for (int i = 0;i<midY;i++) vminus[i] = vtop[i] - vbottom[i];

    vector<int> vTop = hadamard(vplus,n/2);
    vector<int> vBottom = hadamard(vminus,n/2);

    for (auto&x:vTop) tmp.push_back(x);
    for (auto&x:vBottom) tmp.push_back(x);

    return tmp;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i =0;i<n;i++) {
        cin >> v[i];
    }
    vector<int> result = hadamard(v,n);
    for (auto &x:result) cout << x << " ";
}
