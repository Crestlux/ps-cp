#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N + 1, 0), b(N + 1, 0);
    vector<vector<ll>> dp(N + 1, vector<ll>(2, -1));
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    dp[1][0] = a[1]; dp[1][1] = b[1];
    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i] + K);
        dp[i][1] = min(dp[i - 1][0] + b[i] + K, dp[i - 1][1] + b[i]);
    }
    cout << min(dp[N][0], dp[N][1]) << "\n";
    return 0;
}
