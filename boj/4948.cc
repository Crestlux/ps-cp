#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr ll bsize = 246913;
    while (1) {
        ll N;
        cin >> N;
        if (N == 0) break;
        bitset<bsize> isPrime;
        isPrime.set();
        ll lim = sqrt(N << 1);
        for (ll i = 2; i <= lim; ++i)
            for (ll j = max(i * i, (N + i - 1) / i * i); j <= (N << 1); j += i)
                isPrime.set(j - N, false);
        if (N == 1) isPrime.set(0, false);
        cout << isPrime.count() + N - bsize - 1 - ll(isPrime.test(0)) << "\n";
    }
    return 0;
}
