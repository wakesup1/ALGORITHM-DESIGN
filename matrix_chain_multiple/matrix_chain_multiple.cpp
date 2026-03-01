#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int p[100];
int main() {
    int N;
    cin >> N;
    vector<vector<int>> m(N+1,vector<int>(N+1));
    for (int i = 0; i < N+1;i++) cin >> p[i];

    // for (int i =0; i <= N;i++) {
    //     for (int j=i+2; j <= N;j++) {
    //         long minVal = INT_MAX;
    //         for (int k =i+1; k < j;k++) {
    //             long w = m[i][k] + m[k][j] + p[i]*p[k]*p[j];
    //             if (w < minVal) {
    //                 cout << i << " " << k << " " << j << "\n";
    //                 minVal = w;
    //             }
    //         }
    //         m[i][j] = minVal;
    //     }
    // }

    for (int L = 2; L <= N;L++) {
        for (int i = 0; i + L <= N;i++) {
            long minVal = INT_MAX;
            for (int k = i+1; k < i+L;k++) {
                long w = m[i][k] + m[k][i+L] + p[i]*p[k]*p[i+L];
                if (w < minVal) {
                    minVal = w;
                }
            }
            m[i][i+L] = minVal;
        }
    }
    cout << m[0][N] ;
}