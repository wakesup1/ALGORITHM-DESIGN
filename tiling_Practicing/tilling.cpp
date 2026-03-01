#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmd {
    int type,x,y;
};

vector<cmd> tilling(int hX, int hY, int x, int y, int n) {
    vector<cmd> tmp, tL, tR, bL, bR;
    if (n==1) return tmp;
    int midX = x + n/2; int midY = y + n/2;
    int cX = midX - 1; int cY = midY - 1;

    // top left
    if (hX < midX && hY < midY) {
        tmp.push_back({0,cX,cY});

        tL = tilling(hX, hY, x,y,n/2); // top left
        tR = tilling(midX, midY-1,midX,y,n/2); // top right
        bL = tilling(midX-1,midY,x,midY,n/2); // bottom left
        bR = tilling(midX,midY,midX,midY,n/2); // bottome right
    }

    // top right
    if (hX >= midX && hY < midY) {
        tmp.push_back({1,cX,cY});

        tL = tilling(midX-1, midY-1, x,y,n/2); // top left
        tR = tilling(hX, hY,midX,y,n/2); // top right
        bL = tilling(midX-1,midY,x,midY,n/2); // bottom left
        bR = tilling(midX,midY,midX,midY,n/2); // bottome right
    }

    // bottom left
    if (hX < midX && hY >= midY) {
        tmp.push_back({2,cX,cY});

        tL = tilling(midX-1, midY-1, x,y,n/2); // top left
        tR = tilling(midX, midY-1,midX,y,n/2); // top right
        bL = tilling(hX,hY,x,midY,n/2); // bottom left
        bR = tilling(midX,midY,midX,midY,n/2); // bottome right
    }

    // bottom right
    if (hX >= midX && hY >= midY) {
        tmp.push_back({3,cX,cY});

        tL = tilling(midX-1, midY-1, x,y,n/2); // top left
        tR = tilling(midX, midY-1,midX,y,n/2); // top right
        bL = tilling(midX-1,midY,x,midY,n/2); // bottom left
        bR = tilling(hX,hY,midX,midY,n/2); // bottome right
    }
    for (auto&x:tL) tmp.push_back(x);
    for (auto&x:tR) tmp.push_back(x);
    for (auto&x:bL) tmp.push_back(x);
    for (auto&x:bR) tmp.push_back(x);
    return tmp;
}

int main() {
    int l, x, y;
    cin >> l >> x >> y;
    vector<cmd> ans = tilling(x,y,0,0,l);
    cout << ans.size() << "\n";
    for (auto&x:ans) {
        cout << x.type << " " << x.x << " " << x.y << "\n";
    }
}