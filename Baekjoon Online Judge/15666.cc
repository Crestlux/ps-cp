#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ret;
void pick(int n, vector<int> &picked, int toPick, const vector<int> &numarr) {
    if (toPick == 0) {
        ret.push_back(picked);
        return;
    }
    for (auto next = numarr.begin(); next < numarr.end(); ++next) {
        if (!picked.empty()) {
            if (picked.back() > *next) continue;
        }
        picked.push_back(*next);
        pick(n, picked, toPick - 1, numarr);
        picked.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> v, arr;
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }
    sort(arr.begin(), arr.end());
    pick(N, v, M, arr);
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for (const auto &i : ret) {
        for (const auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
