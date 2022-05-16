#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int MAX_VAL = 1e7;
    int C, S, T;
    cin >> C;
    while (C--) {
        cin >> S >> T;
        function<int(int, int, int)> cnt = [&](int src, int dest, int ret) ->int {
            if (src > dest) return MAX_VAL;
            else if (src < dest) {
                int first = cnt(src << 1, dest + 3, ret + 1);
                int second = cnt(src + 1, dest, ret + 1);
                return min(first, second);
            }
            else return ret;
        };
        cout << cnt(S, T, 0) << "\n";
    }
    return 0;
}
