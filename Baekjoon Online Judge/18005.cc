#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if (n & 1) cout << "0\n";
    else if ((n / 2) & 1) cout << "1\n";
    else cout << "2\n";
    return 0;
}
