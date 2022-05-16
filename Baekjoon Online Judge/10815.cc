#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    map<int, bool> v;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.insert({ num, true });
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        if (v.find(num) != v.end())cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}
