#include <bits/stdc++.h>
using namespace std;
void pick(int n, vector<int> &picked, int toPick) {
    if (toPick == 0) {
        for (const auto &ele : picked) {
            cout << ele << " ";
        }
        cout << "\n";
        return;
    }
    for (int next = 1; next <= n; ++next) {
        if (!picked.empty()) {
            bool same = false;
            for (const auto &ele : picked) {
                if (next == ele) same = true;
            }
            if (same == true) continue;
        }
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; vector<int> v;
    cin >> N >> M;
    pick(N, v, M);
    return 0;
}
