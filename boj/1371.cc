#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int alph[26] = { 0, }, maxcnt = -1e8; string s1;
    while (getline(cin, s1)) {
        for (auto it = s1.begin(); it < s1.end(); it++) {
            if (*it == ' ') continue;
            else alph[static_cast<int>(*it) - 'a']++;
        }
    }
    for (const auto &ele : alph) {
        maxcnt = max(maxcnt, ele);
    }
    for (int i = 0; i < 26; i++) {
        if (alph[i] == maxcnt) cout << static_cast<char>(i + 'a');
    }
    cout << "\n";
    return 0;
}
