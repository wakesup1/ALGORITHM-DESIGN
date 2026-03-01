#include <iostream>
#include <map>
#include <vector>

using namespace std;

void merger(map<int,int> &m, int L, int R) {
    int newL = L, newR = R;
    vector<map<int,int>::iterator> del;
    auto fpos = m.lower_bound(L);

    if (fpos != m.begin()) fpos--;

    while (R >= fpos->first-1 && fpos != m.end()) {
        if (L > fpos->second +1  ) {
            fpos++;
            continue;
        }
        newR = max(fpos->second,newR);
        newL = min(fpos->first,newL);
        del.push_back(fpos);
        fpos++;
    }

    for (auto it: del) m.erase(it);

    m.insert({newL, newR});
}   

int main() {
    map<int,int> m;
    int n,l,r;
    cin >> n;
    while(n--) {
        cin >> l >> r;
        merger(m, l, r);
    }
    for (auto &[k, j ] : m) {
        cout << k << " " << j << '\n';
    }
}