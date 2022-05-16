#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, d, ret; string s1, temp; bool chk = false;
    cin >> N >> d;
    vector<ll> num(d);
    for (int i = 0; i < d; i++) {
        num[i] = i;
    }
    while (N) {
        s1 += to_string(N % d);
        N /= d;
    }
    reverse(s1.begin(), s1.end());
    do {
        temp.clear();
        for (auto it = num.begin(); it != num.end(); ++it) {
            if (*num.begin() == 0) break;
            temp += to_string(*it);
        }
        if (!temp.empty() && !s1.empty()) {
            if (stoll(temp, NULL, d) > stoll(s1, NULL, d)) {
                chk = true; break;
            }
            else continue;
        }
    } while (next_permutation(num.begin(), num.end()));
    if (chk) ret = stoll(temp, NULL, d);
    else ret = -1;
    cout << ret << "\n";
    return 0;
}
