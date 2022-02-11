#include <bits/stdc++.h>
using namespace std;
constexpr int sieve_size = 1e6 * 5 + 1;
int sieve[sieve_size];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    sieve[0] = sieve[1] = -1;
    for (int i = 2; i < sieve_size; i++) sieve[i] = i;
    for (int i = 2; i * i < sieve_size; i++) {
        if (sieve[i] == i) {
            for (int j = i * i; j < sieve_size; j += i) {
                if (sieve[j] == j) sieve[j] = i;
            }
        }
    }
    int N;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        while (num > 1) {
            cout << sieve[num] << " ";
            num /= sieve[num];
        }
        cout << "\n";
    }
    return 0;
}
