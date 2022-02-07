#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        string s1, temp;
        getline(cin, s1);
        if (s1 == "#") break;
        regex re("[aeiou]", regex::icase);
        for (auto it = sregex_iterator(s1.begin(), s1.end(), re); it != sregex_iterator(); ++it) {
            smatch match = *it;
            temp += match.str();
        }
        cout << temp.length() << "\n";
    }
    return 0;
}
