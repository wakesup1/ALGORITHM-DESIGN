#include <iostream>
#include <vector>
using namespace std;

void perm(int n, int len, vector<int> &sol) {
    if (len < n) {
        sol[len] = 0;
        perm(n,len+1,sol);
        sol[len] = 1;
        perm(n,len+1,sol);
    } else {
        for (auto x:sol) cout << x << " ";
        cout << "\n";
    }
} 

int main () {
    int n ;
    cin >> n;
    vector<int> sol(n);
    perm(n,0,sol);
}