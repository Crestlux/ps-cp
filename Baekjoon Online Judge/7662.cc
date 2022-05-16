#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, N, num; char op; bool removed[int(1e6 + 1)], rmfull = false;
    priority_queue<pair<int, int>> maxheap; priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    deque<pair<int, int>> ret;
    cin >> T;
    while (T--) {
        memset(removed, 0, sizeof(removed));
        while (!maxheap.empty()) maxheap.pop();
        while (!minheap.empty()) minheap.pop();
        if (!ret.empty()) ret.clear();
        rmfull = false;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> op >> num;
            if (op == 'I') {
                maxheap.push({ num, i });
                minheap.push({ num, i });
            }
            else if (op == 'D') {
                for (int j = 0; j < N; j++) {
                    if (!removed[j]) break;
                    else {
                        if (j == N - 1 && removed[N - 1]) rmfull = true;
                    }
                }
                if (!rmfull) {
                    if (num == 1) {
                        while (!maxheap.empty() && removed[maxheap.top().second] == true) maxheap.pop();
                        if (!maxheap.empty()) {
                            removed[maxheap.top().second] = true;
                            maxheap.pop();
                        }
                    }
                    else if (num == -1) {
                        while (!minheap.empty() && removed[minheap.top().second] == true) minheap.pop();
                        if (!minheap.empty()) {
                            removed[minheap.top().second] = true;
                            minheap.pop();
                        }
                    }
                }
            }
        }
        while (!maxheap.empty()) {
            if (removed[maxheap.top().second]) maxheap.pop();
            else {
                ret.push_back(maxheap.top());
                maxheap.pop();
            }
        }
        if (ret.empty()) cout << "EMPTY";
        else cout << ret.front().first << " " << ret.back().first;
        cout << "\n";
    }
    return 0;
}
