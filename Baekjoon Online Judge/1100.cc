#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char graph[9][9]; int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> graph[i][j];
            if ((i + j) % 2 == 0 && graph[i][j] == 'F')cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
