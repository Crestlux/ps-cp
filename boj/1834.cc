#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ull N, sum = 0;
    cin >> N;
    sum = ((N - 1) * N * (N + 1)) >> 1;
    cout << sum << "\n";
    return 0;
}
