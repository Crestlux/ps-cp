#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int graph[101][101];
bool visited[101][101];
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0,0 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, maxh = -1, ret = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
            maxh = max(maxh, graph[i][j]);
        }
    }
    for (int h = 0; h < maxh; ++h) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        function<void(int, int)> dfs = [&](int y, int x) {
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (!visited[ny][nx] && graph[ny][nx] > h) {
                    visited[ny][nx] = true;
                    dfs(ny, nx);
                }
            }
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j] && graph[i][j] > h) {
                    visited[i][j] = true;
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        ret = max(cnt, ret);
    }
    cout << ret << "\n";
    return 0;
}
