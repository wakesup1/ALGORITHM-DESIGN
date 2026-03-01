#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q,x,c,p;
    vector<pair<int,int>> v;
    vector<int> aux;
    cin >> n >> q;
    while (n--) {
        cin >> x >> c;
        v.push_back(make_pair(x,c));
    }
    sort(v.begin(), v.end());
    for (auto [k, c]: v) {
        aux.push_back(c + ((aux.size() == 0) ? 0:*aux.rbegin()));
    }
    while (q--) {
        cin >> p; 
        auto pos = lower_bound(aux.begin(), aux.end(), p) - aux.begin();
        cout << v[pos].first << "\n";
    }
    // for (auto x: aux) {
    //     cout << x << ", ";
    // }
}