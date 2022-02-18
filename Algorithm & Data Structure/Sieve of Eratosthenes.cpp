#include <bits/stdc++.h>
using namespace std;
int main() {
    //Sieving till root
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
    //Find primes in range
    /*  Case 1. pre-generate all prime numbers up to sqrt(R),
                and use those primes to mark all composite numbers in the segment [L, R].
            Time Complexity : O((R-L+1)loglogR + sqrt(R)loglog(sqrt(R)))
        Case 2. don't pre-generate all prime numbers
            Time Complexity : O((R-L+1)logR + sqrt(R))
    */
    //bitset can be used instead of vector
    //Case 1: Time Complexity : O((R-L+1)loglogR + sqrt(R)loglog(sqrt(R)))

    //Case 2: Time Complexity : O((R-L+1)logR + sqrt(R))
    auto segmentedSieveCase2 = [&](long long L, long long R) -> vector<bool> {
        vector<bool> isPrime(R - L + 1, true);
        long long lim = sqrt(R);
        for (long long i = 2; i <= lim; ++i)
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j - L] = false;
        if (L == 1) isPrime[0] = false;
        return isPrime;
    };
    //


    return 0;
}
/* Reference : http://e-maxx.ru/index.php
               https://cp-algorithms.com/index.html */