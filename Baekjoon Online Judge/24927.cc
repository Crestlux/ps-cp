#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K, cnt = 0;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        while (!(num & 1)) {
            num >>= 1;
            ++cnt;
        }
        if (cnt >= K) break;
    }
    cnt >= K ? cout << "1\n" : cout << "0\n";
    return 0;
}
