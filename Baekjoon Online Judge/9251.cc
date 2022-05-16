#include <bits/stdc++.h>
using namespace std;
int LCS[1001][1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    memset(LCS, 0, sizeof(LCS));
    cin >> s1 >> s2;
    int s1_len = s1.length(), s2_len = s2.length();
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            if (s1.at(i - 1) == s2.at(j - 1)) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    cout << LCS[s1_len][s2_len] << "\n";
    return 0;
}
