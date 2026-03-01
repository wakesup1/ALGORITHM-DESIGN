#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isZeroMatrix(vector<vector<int>> &S) {
    for (auto &c:S) {
        for (auto &e:c) if (e != 0) return false;
    }
    return true;
}

int triforceNumber(vector<vector<int>> &A) {
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    vector<int> tmp = {A[0][0],A[0][1],A[1][0]};
    for (auto &x:tmp) {
        if (x == 0) c0++;
        if (x == 1) c1++;
        if (x == 2) c2++;
        if (x == 3) c3++;
    }
    if (c0 > 0) return 0;
    if (c1 == c2 && c2 == c3 && c1 == c3) return 0;
    if (c1 >= 2) return 1;
    if (c2 >= 2) return 2;
    if (c3 >= 2) return 3;
}

int typeCheck(vector<vector<int>> &A) {
    if (A.size() == 2) {
        return (A[1][1] == 0 ? triforceNumber(A): 0);
    }
    int midRow = A.size()/2;
    int midCol = A[0].size()/2;

    vector<vector<int>> P(midRow), Q(midRow), R(midRow), S(midRow);

    for (int i = 0; i < midRow;i++) {
        for (int j = 0;j < midCol;j++) {
            P[i].push_back(A[i][j]);
        }
    }

    for (int i = 0; i < midRow;i++) {
        for (int j = midCol;j < A[0].size();j++) {
            Q[i].push_back(A[i][j]);
        }
    }

    for (int i =  midRow; i < A.size();i++) {
        for (int j = 0;j < midCol;j++) {
            R[i - midRow].push_back(A[i][j]);
        }
    }

    for (int i = midRow; i < A.size();i++) {
        for (int j = midCol;j < A[0].size();j++) {
            S[i - midRow].push_back(A[i][j]);
        }
    }

    vector<int> result(3); // For each zone

    result[0] = typeCheck(P);
    result[1] = typeCheck(Q);
    result[2] = typeCheck(R);

    int c1 = 0, c2 = 0, c3 = 0, represent;
    
    for (auto &x : result) {
        if (x == 0) return 0;
        if (x == 1) c1++;
        if (x == 2) c2++;
        if (x == 3) c3++;
    }

    if (c1 == c2 && c2 == c3 && c1 == c3) represent = 0;
    if (c1 >= 2) represent = 1;
    if (c2 >= 2) represent = 2;
    if (c3 >= 2) represent = 3;
    
    return (isZeroMatrix(S) ? represent : 0);
}

int main() {
    int n;
    for (int k = 0; k < 3;k++) {
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i<n;i++){  
            for (int j = 0; j<n ;j++){ 
                int h;
                cin >> h;
                arr[i].push_back(h);
            }
        }
        cout << typeCheck(arr) << "\n";
    }
}