#include <iostream>
#include <vector>

using namespace std;

int help(vector<int> &v,int &target) {
    int L = 0;
    int R = v.size() - 1;
    int mid = (L+R)/2;
    auto it = v.begin();
    while (L <= R) {
        
        if (*(it + mid) <= target && *(it + mid + 1) > target) {
            int e = 0;
            while (*(it+mid) == *(it+mid+1)) mid++;
            return mid;
        }
        if (*(it + mid) > target) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
        mid = (L+R)/2;
    }
    if (mid == v.size() - 1) return v.size() - 1;
    return -1;
}

int main() {
    int n, m, target;
    cin >> n >> m;
    vector<int> temp(n);
    for (int i =0;i<n;i++) {
        cin >> temp[i];
    }
    while (m--) {
        cin >> target;
        cout << help(temp, target) << "\n";
    }
}
