#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int alph[26] = { 0, };
    string s1;
    cin >> s1;
    int len = s1.length();
    for (int i = 0; i < len; i++) {
        alph[s1.at(i) - 'a']++;
    }
    for (const auto &ele : alph) {
        cout << ele << " ";
    }
    return 0;
}
