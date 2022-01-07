#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    while (1) {
        int num; string s1, s2;
        cin >> num;
        if (num == 0) break;
        s2 = s1 = to_string(num);
        reverse(s2.begin(), s2.end());
        if (s1 == s2) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
