#include <iostream>
using namespace std;
int pos[20]; 
int n;
int ans = 0;

bool check(int row, int col) {
    for (int i = 0; i < row;i ++) {
        if (pos[i] == col) return false;
        if (abs(row - i) == abs(col - pos[i])) return false;
    }
    return true;
}

void solve(int row) {
    if (row == n) ans++;
    else {
        for (int i = 1; i <= n;i++) {
            if (check(row, i)) {
                pos[row] = i;
                solve(row+1);
                pos[row] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    solve(0);
    cout <<ans;
}