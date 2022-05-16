#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; constexpr int mod = 1000000007;
    int dp[1516][3];
    cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[2][0] = 1, dp[2][1] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    cout << dp[N][0] << "\n";
    return 0;
}
