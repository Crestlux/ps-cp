#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    v[N] = v[0];
    int len = v[0].length();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (v[j].at(i) != v[j + 1].at(i)) {
                v[N].at(i) = '?';
                break;
            }
            else continue;
        }
    }
    cout << v[N] << "\n";
    return 0;
}
