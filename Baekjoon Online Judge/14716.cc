#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int graph[251][251]; bool visited[251][251];
int dx[] = { 0,0,-1,1,-1,1, -1,1 }, dy[] = { -1,1,0,0,-1,-1,1,1 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
        }
    }
    function<void(int, int)> dfs = [&](int y, int x) {
        for (int i = 0; i < 8; ++i) {
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
                dfs(i, j);
                ++ret;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
