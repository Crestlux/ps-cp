#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 987654321;
vector<pair<int, int>> graph[50001];
int dist[50001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A_i, B_i, C_i;
        cin >> A_i >> B_i >> C_i;
        graph[A_i].push_back({ B_i, C_i });
        graph[B_i].push_back({ A_i, C_i });
    }
    fill(dist, dist + 50001, INF);
    function<void(int)> dijkstra = [&](int start) -> void {
        priority_queue<pair<int, int>> pq;
        pq.push({ 0,start });
        dist[start] = 0;
        while (!pq.empty()) {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (dist[cur] < cost) continue;
            for (int i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i].first;
                int next_cost = graph[cur][i].second;
                if (dist[next] > cost + next_cost) {
                    dist[next] = cost + next_cost;
                    pq.push({ -dist[next], next });
                }
            }
        }
    };
    dijkstra(1);
    cout << dist[N] << "\n";
    return 0;
}
