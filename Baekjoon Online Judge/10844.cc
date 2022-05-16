#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dp[101][10];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int mod = 1000000000;
    int sum = 0;
    for (int i = 0; i < 10; ++i) dp[1][i] = 1;
    for (int i = 2; i < 101; ++i) {
        dp[i][0] = dp[i - 1][1]; dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j + 1] % mod) % mod;
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < 9; ++i) {
        sum = (sum + dp[N][i] % mod) % mod;
    }
    cout << sum << "\n";
    return 0;
}
