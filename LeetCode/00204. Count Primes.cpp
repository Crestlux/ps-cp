class Solution {
public:
    int countPrimes(int n) {
        constexpr int sieve_size = 1e6 * 5 + 1; int ret = 0;
        bool sieve[sieve_size];
        fill(sieve, sieve + sieve_size, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (!sieve[i]) continue;
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            if(sieve[i]) ret++;
        }
        return ret;
    }
};
