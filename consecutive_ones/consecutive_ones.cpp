#include <iostream>
#include <vector>

using namespace std;

void consecutiveOnes(int n, int k, int len, int chosen, vector<int> &sol, int cons) {
    if (len < n) {
        sol[len] = 0;
        consecutiveOnes(n,k,len+1,chosen,sol,cons >= k ? cons:0);
        sol[len] = 1;
        consecutiveOnes(n,k,len+1,chosen+1, sol, cons+1);
    } else {
        if (cons>=k) {
            for (auto x:sol) cout << x;
            cout << "\n";
        }
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> sol(n);
    consecutiveOnes(n,k,0,0,sol,0);
}