#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, W, H; double d;
    cin >> N >> W >> H;
    d = sqrt(W * W + H * H);
    for (int i = 0; i < N; ++i) {
        int len;
        cin >> len;
        if (len <= d) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}
