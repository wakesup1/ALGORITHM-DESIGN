#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<int> &v, int &q) {
    for (int i =0;i<v.size();i++) {
        int target = q-v[i];
        auto r = v.begin() + v.size() -1;
        auto l = v.begin()+i+1;
        while (l != v.end() && r > l) {
            int x = *r + *l;
            if (target - x == 0) {
                //cout << v[i] << "+" << *l << "+" << *r << '\n';
                return true;
            }
            if (target - x > 0) l++;
            else if (target - x < 0) r--;
        }

    }
    return false;
}
int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    while (m--) {
        cin >> x;
        cout << ((helper(v,x)) ? "YES\n":"NO\n"); 
    }
}