#include <bits/stdc++.h>
using namespace std;
constexpr int s_size = 1e6;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, dp[1000][1000]; bool sieve[s_size];
    memset(dp, -1, sizeof(dp));
    fill(sieve, sieve + s_size, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= s_size; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= s_size; j += i)
                sieve[j] = false;
        }
    }
    cin >> N;
    dp[1][1] = 0;
    function<int(int, int)> calc = [&](int i, int j) -> int {
        if (i < 1 || j < 1) return 0;
        int &ret = dp[i][j];
        if (ret != -1) return ret;
        int concat = stoi(to_string(i) + to_string(j));
        ret = max(calc(i - 1, j), calc(i, j - 1));
        if (sieve[concat]) ret++;
        return ret;
    };
    calc(N, N);
    cout << dp[N][N] << "\n";
    return 0;
}
