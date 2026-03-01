#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right) {
    int midX = (left + right) >> 1;
    int midY = (top + bottom) >> 1;
    if (a == 0) {
        v[midY][midX] = b;
        return;
    }
    recur(v,a-1,b,top,midY,left,midX);
    recur(v,a-1,b-1,top,midY,midX,right);
    recur(v,a-1,b+1,midY,bottom,left,midX);
    recur(v,a-1,b,midY,bottom,midX,right);
}

int main () {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> v(1<<a);
    for (int i = 0; i < 1 << a;i++) {
        v[i].resize(1<<a);
    }
    recur(v ,a ,b ,0 ,1 << a ,0 ,1 << a);
    for (auto &x:v) {
        for (auto &y:x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}