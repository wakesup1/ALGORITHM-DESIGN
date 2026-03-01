#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> k >> n;
    int c[1001] = {0};
    int a[1001] = {0};
    for (int i = 0;i<k;i++) {
        cin >> c[i];
    }
    for (int i = 0;i < k;i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n-k;i++) {
        long long tmp = 0;
        for (int j = 0; j < k;j++) {
            tmp = (tmp + (c[j])%32717*(a[k+i-j-1])%32717)%32717;
            if (tmp < 0) tmp += 32717;
        }
        a[k+i] = tmp;
    }
    cout << a[n];
}
