#include <bits/stdc++.h>
using namespace std;
int c_mod[1001][1001];
constexpr int mod = 10007;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(c_mod, -1, sizeof(c_mod));
    int N, K;
    cin >> N >> K;
    function<int(int, int)> CombinationMod = [&](int N, int K) ->int {
        int &ret = c_mod[N][K];
        if (ret != -1) return ret;
        else if (K == 0 || N == K) return ret = 1;
        else {
            return ret = (CombinationMod(N - 1, K - 1) % mod + CombinationMod(N - 1, K) % mod) % mod;
        }
    };
    cout << CombinationMod(N, K) << "\n";
    return 0;
}
