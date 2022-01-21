#include <bits/stdc++.h>
using namespace std;

void pick(int n, vector<int> &picked, int toPick, const vector<int> &numarr) {
    if (toPick == 0) {
        for (const auto &ele : picked) {
            cout << ele << " ";
        }
        cout << "\n";
        return;
    }
    for (auto next = numarr.begin(); next < numarr.end(); ++next) {
        if (!picked.empty()) {
            bool same = false;
            for (const auto &ele : picked) {
                if (*next == ele) same = true;
            }
            if (same == true) continue;
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
    return 0;
}
