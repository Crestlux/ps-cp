#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, D, dist[10001]; vector<pair<int, int>> graph[10001];
    constexpr int INF = 987654321;
    fill(dist, dist + 10001, INF);
    cin >> N >> D;
    for (int i = 0; i < D; i++) {
        graph[i].push_back({ i + 1, 1 });
    }
    for (int i = 0; i < N; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        graph[u].push_back({ v, dist });
    }
    function<void(int)> dijkstra = [&](int start) {
        priority_queue<pair<int, int>> pq;
        pq.push({ 0, start });
        dist[start] = 0;
        while (!pq.empty()) {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (dist[cur] < cost) continue;
            for (size_t i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i].first;
                int next_cost = graph[cur][i].second;
                if (dist[next] > cost + next_cost) {
                    dist[next] = cost + next_cost;
                    pq.push({ -dist[next], next });
                }
            }
        }
    };
    dijkstra(0);
    cout << dist[D] << "\n";
    return 0;
}
