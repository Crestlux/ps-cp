#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    set<string> s; string s1;
    cin >> s1;
    int s1len = s1.length();
    for (int i = 0; i < s1len; ++i) {
        for (int j = i; j < s1len; ++j) {
            s.insert(s1.substr(i, j - i + 1));
        }
    }
    cout << s.size() << "\n";
    return 0;
}
