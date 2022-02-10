#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        double x, y;
        cin >> x >> y;
        if (y - x <= 3) cout << y - x << "\n";
        else cout << ceil(sqrt(y - x) * 2 - 1) << "\n";
    }
    return 0;
}
