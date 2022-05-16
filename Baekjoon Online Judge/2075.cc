#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            pq.push(num);
            if (static_cast<int>(pq.size()) > N) pq.pop();
        }
    }
    cout << pq.top() << "\n";
    return 0;
}
