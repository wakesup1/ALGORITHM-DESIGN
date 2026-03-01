#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void perm(int n, int len, vector<int> &sol, vector<bool> &use, vector<vector<int>> &p) {
    if (len < n) {
        for (int i = 0; i < n;i++) {
            if (use[i] == false) {
                
                for (auto before: p[i]) {
                    if (use[before] == true) return;
                }
                use[i] = true;
                sol[len] = i;
                perm(n, len+1, sol, use, p);
                use[i] = false;
            }
        }
    } else {
        for (auto x: sol) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> priority(n);
    while (m--) {
        cin >> a >> b;
        priority[a].push_back(b);
    }

    vector<int> sol(n);
    vector<bool> use(n);

    perm(n,0,sol,use,priority);
}