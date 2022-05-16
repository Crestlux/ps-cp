#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int graph[51][51];
bool visited[51][51];
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0,0 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, M, N, K;
    cin >> T;
    while (T--) {
        int ret = 0;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cin >> M >> N >> K;
        for (int i = 0; i < K; ++i) {
            int p, q;
            cin >> p >> q;
            graph[q][p] = 1;
        }
        function<void(int, int)> dfs = [&](int y, int x) {
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                if (!visited[ny][nx] && graph[ny][nx]) {
                    visited[ny][nx] = true;
                    dfs(ny, nx);
                }
            }
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j] && graph[i][j]) {
                    visited[i][j] = true;
                    ++ret;
                    dfs(i, j);
                }
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
