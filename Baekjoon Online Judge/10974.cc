#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; vector<int> v;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
    do {
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
