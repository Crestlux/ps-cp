#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int CCW(const pll &x, const pll &y, const pll &z) {
    ll ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pll A, B, R1, R2, R3, R4; ll ans = 0; int T;
    cin >> T;
    while (T--) {
        cin >> A.first >> A.second >> B.first >> B.second;
        if (A > B) swap(A, B);
        cin >> R2.first >> R2.second >> R4.first >> R4.second;
        if (R2 > R4) swap(R2, R4);
        R1 = { R4.first, R2.second }, R3 = { R2.first, R4.second };
        if (R2 > R1) swap(R2, R1);
        if (R3 > R4) swap(R3, R4);
        if (R3 > R2) swap(R3, R2);
        if (R4 > R1) swap(R4, R1);
        function<void(pll, pll, pll, pll)> chk = [&](pll a, pll b, pll c, pll d) {
            if (CCW(a, b, c) * CCW(a, b, d) <= 0) {
                if (CCW(a, b, c) * CCW(a, b, d) == 0 && CCW(c, d, a) * CCW(c, d, b) == 0) {
                    if (a <= d && b >= c) ans = 1;
                    else ans = 0;
                }
                else if (CCW(a, b, c) * CCW(a, b, d) <= 0 && CCW(c, d, a) * CCW(c, d, b) <= 0) ans = 1;
                else ans = 0;
            }
            else ans = 0;
        };
        chk(A, B, R1, R2);
        if (ans != 1) chk(A, B, R2, R3);
        if (ans != 1) chk(A, B, R3, R4);
        if (ans != 1) chk(A, B, R4, R1);
        if (ans != 1) {
            if (R2.first <= A.first && B.first <= R1.first && R3.second <= min(A.second, B.second) && max(A.second, B.second) <= R2.second) ans = 1;
        }
        ans == 1 ? cout << "T\n" : cout << "F\n";
    }
    return 0;
}
