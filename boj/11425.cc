#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = 0; map<string, int> m; string s1;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> s1;
        m[s1]++;
    }
    for (int i = 0; i < M; ++i) {
        cin >> s1;
        if (m.find(s1) != m.end()) ++ret;
    }
    cout << ret << "\n";
    return 0;
}
