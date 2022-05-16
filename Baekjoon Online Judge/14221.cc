#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int INF = 987654321;
    int n, m, p, q, dist[5001]; vector<pair<int, int>> graph[5001];
    vector<int> house, conv; vector<tuple<int, int, int>> vec;
    cin >> n >> m;
    while (m--) {
        int u, v, dst;
        cin >> u >> v >> dst;
        graph[u].push_back({ v,dst });
        graph[v].push_back({ u,dst });
    }
    cin >> p >> q;
    for (int i = 0; i < p; i++) {
        int house_num;
        cin >> house_num;
        house.push_back(house_num);
    }
    for (int i = 0; i < q; i++) {
        int conv_num;
        cin >> conv_num;
        conv.push_back(conv_num);
    }
    for (int i = 0; i < p; i++) {
        fill(dist, dist + 5001, INF);
        function<void(int)> dijkstra = [&](int start) -> void {
            priority_queue<pair<int, int>> pq;
            pq.push({ 0,start });
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
        dijkstra(house[i]);
        for (int j = 0; j < q; j++) {
            vec.push_back({ house[i],conv[j], dist[conv[j]] });
        }
    }
    sort(vec.begin(), vec.end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b) ->bool {
        if (get<2>(a) == get<2>(b)) return get<0>(a) < get<0>(b);
        else return get<2>(a) < get<2>(b);
        });
    cout << get<0>(vec[0]) << "\n";
    return 0;
}
