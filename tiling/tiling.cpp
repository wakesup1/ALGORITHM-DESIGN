#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmd {
    int type, x, y;
};

vector<cmd> ans;

void tiling(int holeX, int holeY, int col, int row, int n) {
    int midX = n >> 1; int midY = midX;
    if (n==1) return;

    // top left type 0
    if (holeX < col + midX && holeY < row + midY) {
        ans.push_back({0, col + midX - 1, row + midY - 1});
        
        tiling(holeX, holeY, col, row, n >> 1); // top left
        tiling(col+midX, row+midY-1, col+midX, row, n >> 1); // top right
        tiling(col+midX-1, row+midY, col, row+midY, n >> 1); // bottom left
        tiling(col+midX, row+midY, col+midX, row+midY, n >> 1); // bottom right
    }

    // top right type 1
    if (holeX >= col + midX && holeY < row + midY) {
        ans.push_back({1, col + midX - 1, row + midY - 1});
        
        tiling(holeX, holeY, col+midX, row, n >> 1); // top right
        tiling(col+midX-1, row+midY-1, col, row, n >> 1); // top left
        tiling(col+midX-1, row+midY, col, row+midY, n >> 1); // bottom left
        tiling(col+midX, row+midY, col+midX, row+midY, n >> 1); // bottom right
    }

    // bottom left type 2
    if (holeX < col + midX && holeY >= row + midY) {
        ans.push_back({2, col + midX - 1, row + midY - 1});
        
        tiling(holeX, holeY, col, row+midY, n >> 1); // bottom left
        tiling(col+midX-1, row+midY-1, col, row, n >> 1); // top left
        tiling(col+midX, row+midY-1, col+midX, row, n >> 1); // top right
        tiling(col+midX, row+midY, col+midX, row+midY, n >> 1); // bottom right
    }

    // bottom right type 3
    if (holeX >= col + midX && holeY >= row + midY) {
        ans.push_back({3, col + midX - 1, row + midY - 1});
        
        tiling(holeX, holeY, col+midX, row+midY, n >> 1); // bottom right
        tiling(col+midX-1, row+midY-1, col, row, n >> 1); // top left
        tiling(col+midX, row+midY-1, col+midX, row, n >> 1); // top right
        tiling(col+midX-1, row+midY, col, row+midY, n >> 1); // bottom left
    }
}

int main() {
    int l,x,y;
    cin >> l >> x >> y;
    tiling(x,y,0,0,l);
    cout << ans.size() << "\n";
    for (auto&x : ans) {
        cout << x.type << " " << x.x << " " << x.y << "\n";
    }
}