#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int svsize = 1050;
    string s1; int sum = 0; bool sieve[svsize];
    fill(sieve, sieve + svsize, true);
    sieve[0] = false;
    for (int i = 2; i * i <= svsize; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= svsize; j += i) {
                sieve[j] = false;
            }
        }
    }
    cin >> s1;
    int slen = s1.length();
    for (int i = 0; i < slen; i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z')
            sum += s1[i] - 'a' + 1;
        else
            sum += s1[i] - 'A' + 27;
    }
    if (sieve[sum]) cout << "It is a prime word.\n";
    else cout << "It is not a prime word.\n";
    return 0;
}
