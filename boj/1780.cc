#include <bits/stdc++.h>
using namespace std;
int paperNum[3] = { 0, };
void paper(vector<vector<int>> &graph, int x, int y, int size) {
    bool allZero, allOne, allMinus;
    allZero = allOne = allMinus = true;
    if (size == 1) {
        paperNum[(graph[y][x] + 1)]++;
        return;
    }
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (graph[i][j] == -1) { allZero = false, allOne = false; }
            else if (graph[i][j] == 0) { allMinus = false, allOne = false; }
            else if (graph[i][j] == 1) { allMinus = false, allZero = false; }
        }
    }
    if (allMinus || allZero || allOne) {
        if (allMinus) {
            paperNum[0]++;
            return;
        }
        else if (allZero) {
            paperNum[1]++;
            return;
        }
        else if (allOne) {
            paperNum[2]++;
            return;
        }
    }
    else {
        paper(graph, x, y, size / 3);
        paper(graph, x + size / 3, y, size / 3);
        paper(graph, x + ((size / 3) << 1), y, size / 3);
        paper(graph, x, y + size / 3, size / 3);
        paper(graph, x + (size / 3), y + size / 3, size / 3);
        paper(graph, x + ((size / 3) << 1), y + size / 3, size / 3);
        paper(graph, x, y + ((size / 3) << 1), size / 3);
        paper(graph, x + (size / 3), y + ((size / 3) << 1), size / 3);
        paper(graph, x + ((size / 3) << 1), y + ((size / 3) << 1), size / 3);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    paper(graph, 0, 0, N);
    for (const auto &ele : paperNum) {
        cout << ele << "\n";
    }
    return 0;
}
