#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
i128 c[101][101];
std::ostream &operator<<(std::ostream &os, __int128 t) {
    string s1;
    while (t > 9) {
        s1 += to_string(int((t % 10)));
        t /= 10;
    }
    s1 += to_string(int(t));
    reverse(s1.begin(), s1.end());
    return os << s1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(c, -1, sizeof(c));
    int n, m;
    cin >> n >> m;
    function< i128(i128, i128)> combination = [&](i128 n, i128 m) -> i128 {
        if (c[n][m] != -1) return c[n][m];
        else if (m == 0 || n == m) { return c[n][m] = 1; }
        else return c[n][m] = combination(n - 1, m) + combination(n - 1, m - 1);
    };
    cout << combination(n, m) << "\n";
    return 0;
}
