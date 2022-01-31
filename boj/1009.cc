#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; vector<int> v[10];
    cin >> T;
    for (int i = 0; i < 10; i++) {
        int tmp = i;
        if (i == 0) { v[i].push_back(10); continue; }
        else v[i].push_back(tmp);
        while (1) {
            tmp = (tmp * i) % 10;
            if (tmp == *v[i].begin()) break;
            else v[i].push_back(tmp);
        }
    }
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << v[a % 10][(b + v[a % 10].size() - 1) % v[a % 10].size()] << "\n";
    }
    return 0;
}
