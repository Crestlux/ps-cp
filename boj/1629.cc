#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll A, B, C, temp = 1, ret;
    cin >> A >> B >> C;
    while (B > 1) {
        if (B & 1) {
            temp = (temp * A) % C;
        }
        A = (A * A) % C;
        B >>= 1;
    }
    ret = (A * temp) % C;
    cout << ret << "\n";
    return 0;
}
