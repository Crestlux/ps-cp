#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int num; bool flag = false;
    vector<int> v;
    while (cin >> num) {
        v.push_back(num);
    }
    int vsize = v.size();
    for (int i = 0; i < vsize - 1; i++) {
        if (v[i] <= v[i + 1]) continue;
        else { flag = true; break; }
    }
    if (flag) cout << "Bad\n";
    else cout << "Good\n";
    return 0;
}
