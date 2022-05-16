#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, H, W;
    cin >> T;
    while (T--) {
        int ans = 0;
        cin >> H >> W;
        vector<vector<char>> graph(H, vector<char>(W));
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                cin >> graph[y][x];
            }
        }
        function<void(int, int, int)> dfs = [&](int y, int x, int depth) -> void {
            static const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0 , -1 };
            if (visited[y][x]) return;
            visited[y][x] = true;
            for (int mov = 0; mov < 4; mov++) {
                int nx = x + dx[mov], ny = y + dy[mov];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || graph[ny][nx] == '.' || visited[ny][nx]) continue;
                else { dfs(ny, nx, depth + 1); }
            }
            if (depth == 0) ++ans;
            else --depth;
        };
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (graph[y][x] == '#') dfs(y, x, 0);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
