#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
typedef std::pair<int,int> pi;

using namespace std;

vector<int> pareto(vector<pi> &arr, int start, int stop) {
    vector<int> tmp;
    if (stop - start == 1) { 
        tmp.push_back(start);
        return tmp;
    }
    int mid = (start + stop) >> 1;
    vector<int> leftPareto = pareto(arr, start, mid);
    vector<int> rightPareto = pareto(arr, mid, stop);
    int firstMaxOfRight = (rightPareto.size() != 0 ? arr[*rightPareto.begin()].second: -1);
    if (firstMaxOfRight != -1) {
        for (auto&x:leftPareto) {
            if (arr[x].second > firstMaxOfRight) tmp.push_back(x);
        }
    } else {
        for (auto &x:leftPareto) tmp.push_back(x);
    }
    for (auto &x:rightPareto) tmp.push_back(x);
    return tmp;
}

int main() {
    int n,x,y;
    cin >> n;
    vector<pi> pos(n);
    for (int i =0;i<n;i++) {
        cin >> x >> y;
        pos[i].first = x;
        pos[i].second = y;
    }
    sort(pos.begin(), pos.end());
    vector<int> p = pareto(pos, 0, pos.size());
    // for (auto&x : p) {
    //     cout << x << " ";
    // }
    cout << p.size();
}