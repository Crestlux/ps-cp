#include <bits/stdc++.h>
using namespace std;
int LCS[1001][1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2, ret;
    memset(LCS, 0, sizeof(LCS));
    cin >> s1 >> s2;
    int s1_len = s1.length(), s2_len = s2.length();
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            if (s1.at(i - 1) == s2.at(j - 1)) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    while (1) {
        static int i = s1_len, j = s2_len;
        if (LCS[i][j] == 0) break;
        const int cur = LCS[i][j];
        if (cur == LCS[i - 1][j]) { --i; }
        else if (cur == LCS[i][j - 1]) { --j; }
        else { ret += s1.at(i - 1); --i; --j; }
    }
    reverse(ret.begin(), ret.end());
    cout << LCS[s1_len][s2_len] << "\n" << ret << "\n";
    return 0;
}
