#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int day_counts[1001];
vector<vector<int>> avail;
int min_students;

bool isCovered() {
    for (int i =1;i<= n;i++) {
        if (day_counts[i] == 0) return false;
    }
    return true;
}

void solve(int n, int len, int count) {
    
    if (count > min_students) return;
    if (isCovered()) {
        min_students = count;
    }

    if (len == m) return;

    // Selected
    for (auto &x: avail[len]) {
        day_counts[x]++;
    }
    solve(n,len+1,count+1);
    // Unselected
    for (auto &x: avail[len]) {
        day_counts[x]--;
    }
    solve(n,len+1,count);
}

int main() {
    cin >> n >> m;
    int k,a;
    min_students = m;
    avail.resize(m);
    for (int i = 0; i<m;i++) {
        cin >> k;
        for (int j = 0;j<k;j++) {
            cin >> a;
            avail[i].push_back(a);
        }
    }
    solve(n, 0, 0);
    cout << min_students;
}