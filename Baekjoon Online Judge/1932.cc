#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triangle, cache;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    triangle.resize(N, vector<int>(N, 0));
    cache.resize(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
            if (i == N - 1) cache[i][j] = triangle[i][j];
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cache[i][j] = max(triangle[i][j] + cache[i + 1][j], triangle[i][j] + cache[i + 1][j + 1]);
        }
    }
    cout << cache[0][0] << "\n";
    return 0;
}
