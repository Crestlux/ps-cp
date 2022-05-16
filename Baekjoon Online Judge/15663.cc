#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ret;
vector<bool> sel;
void pick(int n, vector<int> &picked, int toPick, const vector<int> &numarr, int before_idx = -1) {
    if (toPick == 0) {
        ret.push_back(picked);
        return;
    }
    for (auto next = numarr.begin(); next < numarr.end(); ++next) {
        if (next - numarr.begin() == before_idx || sel[next - numarr.begin()]) continue;
        picked.push_back(*next);
        sel[next - numarr.begin()] = true;
        pick(n, picked, toPick - 1, numarr, next - numarr.begin());
        sel[next - numarr.begin()] = false;
        picked.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> v, arr;
    cin >> N >> M;
    arr.resize(N); sel.resize(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }
    sort(v.begin(), v.end());
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
