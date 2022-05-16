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
    int smallest = picked.empty() ? 1 : picked.back() + 1;
    for (int next = smallest; next <= n; ++next) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> v;
    cin >> N >> M;
    pick(N, v, M);
    return 0;
}
