#include <bits/stdc++.h>
using namespace std;
constexpr int t_size = 1e5 + 1, dmax = 18;
int parent[t_size][dmax], N, M;
vector<int> adj[t_size];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(parent, -1, sizeof(parent));
    cin >> N;
    vector<int> depth(N + 1, -1);
    depth[1] = 0;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    function<void(int)> makeTree = [&](int cur) -> void {
        for (const auto &next : adj[cur]) {
            if (depth[next] == -1) {
                parent[next][0] = cur;
                depth[next] = depth[cur] + 1;
                makeTree(next);
            }
        }
    };
    makeTree(1);
    for (int i = 0; i < dmax - 1; i++) {
        for (int j = 2; j <= N; j++) {
            if (parent[j][i] != -1) parent[j][i + 1] = parent[parent[j][i]][i];
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; diff != 0; j++) {
            if (diff % 2) u = parent[u][j];
            diff >>= 1;
        }
        if (u != v) {
            for (int j = dmax - 1; j >= 0; j--) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j], v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u << "\n";
    }
    return 0;
}
