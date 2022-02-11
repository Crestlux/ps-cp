#include <bits/stdc++.h>
using namespace std;
int main() {
    constexpr int sieve_size = 1e6 * 5 + 1;
    bool sieve[sieve_size];
    fill(sieve, sieve + sieve_size, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i < sieve_size; i++) {
        if (!sieve[i]) continue;
        for (int j = i * i; j < sieve_size; j += i) {
            sieve[j] = false;
        }
    }
    return 0;
}
