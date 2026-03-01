#include <iostream>
#include <vector>
using namespace std;
void genBarcode(int n, int k, int len, int chosen, vector<int> &sol){
    if (len < n) {
        if (len - chosen < n - k) {
            sol[len] = 0;
            genBarcode(n,k,len+1,chosen,sol);
        }
        if (chosen < k){
            sol[len] = 1;
            genBarcode(n,k,len+1,chosen+1,sol);
        } 
    } else {
        for (int x:sol) cout << x;
        cout << "\n";
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    genBarcode(n,k,0,0,sol);
}