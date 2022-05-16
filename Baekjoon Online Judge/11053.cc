#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, cache[1010]; vector<int> v;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    function<int(int)> LIS = [&](int start) -> int {
        int &ret = cache[start + 1];
        if (ret != -1) return ret;
        ret = 1;
        for (int next = start + 1; next < N; next++) {
            if (start == -1 || v[start] < v[next]) ret = max(ret, LIS(next) + 1);
        }
        return ret;
    };
    cout << LIS(-1) - 1 << "\n";
    return 0;
}
