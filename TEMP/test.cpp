#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &v) {
    vector<vector<int>> tmp(v.size(), vector<int>(v[0].size()));
    for (int i = 0;i<v.size();i++) {
        for (int j = 0; j < v[i].size();j++) {
            tmp[j][i] = v[i][j];
        }
    }
    return tmp;
}

int main() {
    int u = 4, v =2;
    cout << u << " " << v;
}