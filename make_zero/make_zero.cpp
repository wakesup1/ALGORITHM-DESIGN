#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
int TARGET = 16777216;

int bfs(int start, vector<int> &dist) {
    int tmp, d, v1, v2;
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while ((!q.empty()))
    {
        tmp = q.front();
        q.pop();
        d = dist[tmp];

        if (tmp%TARGET == 0) return d;

        v1 = (tmp + 1) % TARGET;
        v2 = (2*tmp) % TARGET;
        
        if (dist[v1] == -1) {
            dist[v1] = d + 1;
            q.push(v1);
        }

        if (dist[v2] == -1) {
            dist[v2] = d + 1;
            q.push(v2);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> dist(TARGET, -1);
    cout << bfs(n, dist);
}