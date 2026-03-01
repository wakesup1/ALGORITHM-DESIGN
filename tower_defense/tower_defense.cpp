#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m, k, w, a, h = 0;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> use;
    vector<int> t(k);
    for (int i = 0; i < m; i++) {
        cin >> a;
        use.push_back(make_pair(a,0));
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        use[i].second = a;
        h += a;
    }
    for (int i = 0; i < k; i++) {
        cin >> a;
        t[i] = a;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (t[i] - w <= use[j].first && use[j].first <= t[i] + w) {
                if (use[j].second > 0) {
                    cout << "comes -> " << t[i] << " shots " << use[j].first << "\n";
                    h -= 1;
                    use[j].second -= 1; 
                    break;
                }
            }
        }
    }
    for (auto x: use) {
        cout << x.first << " "<< x.second << '\n';
    }
    cout << h;
}