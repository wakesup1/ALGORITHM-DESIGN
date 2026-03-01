#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m,x;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i<n;i++) {
        cin >> x;
        v[i] = x;
    }
    while (m--) {
        cin >> x;
        int c = 0;
        auto it = v.begin();
        while (it != v.end() && *it != x) {
            if (*it > x)c++;
            it++;
        } 
        cout << c <<"\n";
    }
}