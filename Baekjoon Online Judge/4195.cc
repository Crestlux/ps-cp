#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_SIZE = 200002;
int parent[MAX_SIZE], t_rank[MAX_SIZE];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (t_rank[x] > t_rank[y]) {
		parent[y] = x;
		t_rank[x] += t_rank[y];
	}
	else {
		parent[x] = y;
		t_rank[y] += t_rank[x];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, F; string s1, s2; map<string, int> m;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int chknew = 0;
		cin >> F;
		for (int i = 0; i < MAX_SIZE; i++) {
			t_rank[i] = 1;
			parent[i] = i;
		}
		for (int j = 0; j < F; j++) {
			cin >> s1 >> s2;
			if (m.count(s1) == 0) {
				m[s1] = chknew;
				chknew++;
			}
			if (m.count(s2) == 0) {
				m[s2] = chknew;
				chknew++;
			}
			Union(m[s1], m[s2]);
			cout << max(t_rank[find(m[s1])], t_rank[find(m[s2])]) << "\n";
		}
	}
	return 0;
}
