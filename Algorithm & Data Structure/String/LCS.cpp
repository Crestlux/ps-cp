#include <bits/stdc++.h>
using namespace std;
int LCS[1001][1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    return 0;
}
/*
Longest Common Substring
    if i == 0 or j == 0:
        LCS[i][j] = 0
    elif string_A[i] == string_B[j]:
        LCS[i][j] = LCS[i - 1][j - 1] + 1
    else:
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
Longest Common Subsequence
    if i == 0 or j == 0:
        LCS[i][j] = 0
    elif string_A[i] == string_B[j]:
        LCS[i][j] = LCS[i - 1][j - 1] + 1
    else:
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
*/
