#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    bool sieve[1010]; int N, K, cnt = 0, ret = -1, s_size = sizeof(sieve) / sizeof(bool);
    fill(sieve, sieve + s_size, true);
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        static bool brkloop = false;
        if (sieve[i]) {
            ++cnt;
            if (cnt == K) {
                ret = i; break;
            }
            for (int j = i * i; j <= N; j += i) {
                if (sieve[j]) ++cnt;
                if (cnt == K) {
                    brkloop = true;
                    ret = j; break;
                }
                sieve[j] = false;
            }
        }
        if (brkloop) break;
    }
    cout << ret << "\n";
    return 0;
}
