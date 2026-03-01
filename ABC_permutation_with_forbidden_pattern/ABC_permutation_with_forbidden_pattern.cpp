#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> used = {0,0,0};
vector<string> ans;
bool allowed(vector<char> &sol, vector<pair<char,char>> &constraint, int len,char place) {
    if (len==0) return true;
    if (find(constraint.begin(), constraint.end(), make_pair(sol[len-1],place)) != constraint.end()){
        return false;
    }
    return true;
}

void solve(vector<char> &sol, int n, int len, vector<int> &used, int chosenA, int chosenB, int chosenC,vector<pair<char,char>> &constraint) {
    if (len < n) {
        if (chosenA < used[0] && allowed(sol,constraint,len,'A')){
            sol[len] = 'A';
            solve(sol, n, len+1, used, chosenA+1, chosenB, chosenC,constraint);
        }
        if (chosenB < used[1]&& allowed(sol,constraint,len,'B')){
            sol[len] = 'B';
            solve(sol, n, len+1, used,chosenA,chosenB+1,chosenC,constraint);
        }
        if (chosenC < used[2]&& allowed(sol,constraint,len,'C')){
            sol[len] = 'C';
            solve(sol, n, len+1, used,chosenA,chosenB,chosenC+1,constraint);
        }
    } else {
        string tmp;
        for (auto&x:sol) tmp += x;
        ans.push_back(tmp);
    }
}

int main() {
    int n,i,j,k,m;
    cin >> n >> i >> j >> k >> m;
    vector<char> sol(n);
    vector<pair<char, char>> constraint(m);
    used[0] = i; used[1] = j; used[2] = k;
    for (int h =0;h<m;h++) {
        char a1,a2;
        cin >> a1 >> a2;
        constraint[h] = make_pair(a1,a2);
    }
    sort(constraint.begin(), constraint.end());
    solve(sol, n, 0, used, 0, 0, 0, constraint);
    cout <<ans.size() << "\n";
    for (auto&x:ans) cout << x << '\n';
}