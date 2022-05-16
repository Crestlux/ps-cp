#include <bits/stdc++.h>
using namespace std;
bool operator< (const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first && a.second < b.second);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; vector<pair<int, int>> v;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < N; i++) {
        int rnk = 1;
        for (int j = 0; j < N; j++) {
            if (v[i] < v[j]) {
                ++rnk;
            }
        }
        cout << rnk << " ";
    }
    cout << "\n";
    return 0;
}
