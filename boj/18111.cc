#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll graph[501][501];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N, M, B, time = 0, maxheight = -1, blockneed = 0;
	vector<pair<ll,ll>> timearr;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			maxheight = max(graph[i][j], maxheight);
		}
	}
	while (1) {
		blockneed = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				blockneed += maxheight - graph[i][j];
			}
		}
		if (B >= blockneed) {
			ll tmp = time;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					time += maxheight - graph[i][j];
				}
			}
			timearr.push_back({ time,maxheight });
			time = tmp;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == maxheight) {
					graph[i][j]--;
					time += 2;
					++B;
				}
			}
		}
		--maxheight;
		if (maxheight == -1) break;
	}
	pair<ll, ll> ans = {2147483647,256};
	for (const auto &ele : timearr) {
		if (ele.first < ans.first) {
			ans.first = ele.first;
			ans.second = ele.second;
		}
		if (ele.first == ans.first) {
			if (ele.second > ans.second) {
				ans.first = ele.first;
				ans.second = ele.second;
			}
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
