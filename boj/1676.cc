#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int, pair<int, int>>> v(501);
    int N, cnt_2 = 0, cnt_5 = 0, vsize = v.size();
    for (int i = 1; i < vsize; i++) {
        v[i] = { i, {0, 0} };
    }
    for (int i = 2; i < vsize; i++) {
        while (v[i].first % 2 == 0) { v[i].first /= 2; v[i].second.first++; }
        while (v[i].first % 5 == 0) { v[i].first /= 5; v[i].second.second++; }
    }
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (v[i].second.first >= 1 || v[i].second.second >= 1) {
            cnt_2 += v[i].second.first;
            cnt_5 += v[i].second.second;
        }
    }
    cout << min(cnt_2, cnt_5) << "\n";
    return 0;
}
