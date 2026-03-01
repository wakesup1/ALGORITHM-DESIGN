#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int modulo(int x, int n, int k) {
    if (n==1) return (x%k);
    int half = modulo(x,n/2,k);
    int reminder = ((half % k) * (half % k))%k;
    if (n%2==1) reminder = (reminder * (x % k)) % k;
    return reminder;
}
int main() {
    int x,n,k;
    cin >> x >> n >> k;
    cout << modulo(x,n,k);
}