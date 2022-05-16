#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
bool visited[10001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, cnt = 0, maxcnt = -1; vector<int> ret;
    ret.reserve(N);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        v[q].push_back(p);
    }
    function<void(int)> dfs = [&](int x) {
        for (int i = 0; i < int(v[x].size()); ++i) {
            if (!visited[v[x][i]]) {
                visited[v[x][i]] = true;
                ++cnt;
                dfs(v[x][i]);
            }
        }
    };
    for (int i = 1; i <= N; ++i) {
        memset(visited, false, sizeof(visited));
        cnt = 0;
        if (!visited[i]) {
            visited[i] = true;
            ++cnt;
            dfs(i);
            if (maxcnt < cnt) {
                maxcnt = cnt;
                ret.clear();
                ret.push_back(i);
            }
            else if (maxcnt == cnt) ret.push_back(i);
        }
    }
    sort(ret.begin(), ret.end());
    for (const auto &e : ret) cout << e << " ";
    cout << "\n";
    return 0;
}
