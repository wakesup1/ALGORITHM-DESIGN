#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mt(int u, int v, int w,int p, int n, long long targetRow, long long targetColumn) {
    if (targetRow == 0 && targetColumn == 0) return u;
    if (targetRow == 0 && targetColumn == 1) return v;
    if (targetRow == 1 && targetColumn == 0) return w;
    if (targetRow == 1 && targetColumn == 1) return p;

    unsigned long long midX = (1LL << (n-1)); unsigned long long midY = midX;

    if (targetRow < midY && targetColumn < midX) {
        return mt(u,v,w,p,n-1,targetRow,targetColumn);
    }

    if (targetRow < midY && targetColumn >= midX) {
        return mt(u,v,w,p,n-1,targetColumn - midX,targetRow);
    }
    
    if (targetRow >= midY && targetColumn < midX) {
        return mt(-u,-v,-w,-p,n-1,targetRow - midY,targetColumn);
    }
    
    if (targetRow >= midY && targetColumn >= midX) {
        return mt(-u,-v,-w,-p,n-1,targetColumn - midX,targetRow - midY);
    }
}

int main() {
    int n, m;
    long long row, col;
    cin >> n >> m;
    int u,v,w,p;
    cin >> u >> v >> w >> p;
    while (m--) {
        cin >> row >> col; row--; col--;
        cout << mt(u,v,w,p,n,row,col) << "\n";
    }
}