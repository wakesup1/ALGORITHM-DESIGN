#include <iostream>
using namespace std;
int p[1002][1002] = {{0}};

int P(int a, int b) {
    if (a < 0 && b < 0) return 0;
    if (a < 0) return 0;
    if (b < 0) return 0;
    return p[a][b];
}

int main() {
    int A[1002][1002] = {{0}};
    int n, m, k, v;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    p[0][0] = A[0][0];
    for (int j = 1; j < m; j++) {
        p[0][j] = p[0][j - 1] + A[0][j];
    }
    for (int i = 1; i < n; i++) {
        p[i][0] = p[i - 1][0] + A[i][0];
        for (int j = 1; j < m; j++) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + A[i][j];
        }
    }
    while (k--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << P(r2,c2) - P(r1-1,c2) - P(r2,c1-1) + P(r1-1,c1-1) << "\n";
    }
}