#include <iostream>
#include <string>

using namespace std;

bool eq(string t1, string t2) {
    if (t1.size() != t2.size()) return false;
    for (int i = 0; i < t1.size();i++) {
        if(t1[i] != t2[i]) return false;
    }
    return true;
}

bool div(string t1, string t2) {
    if (t1.size() != t2.size()) return false;
    if (t1.size() == 1) return eq(t1,t2);
    string a1, a2, b1, b2;
    int mid = t1.size()/2;
    for (int i = 0; i < mid;i++) {
        a1 += t1[i];
        a2 += t1[i+mid];
        b1 += t2[i];
        b2 += t2[i+mid];
    }
    return (div(a1, b1) && div(a2, b2)) || (div(a1, b2) && div(a2, b1));
}

int main()  {
    string t1, t2;
    cin >> t1;
    cin >> t2;
    cout << (div(t1, t2) ? "YES":"NO");
}