#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    auto CCW = [&](const pdd &x, const pdd &y, const pdd &z) -> double {
        double ret = x.first * y.second + y.first * z.second + z.first * x.second;
        ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
        return ret / 2.0;
    };
    cout << fixed; cout.precision(1);
    int N; double ret = 0.0;
    cin >> N;
    vector<pdd> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i < N; i++) {
        ret += CCW(v[0], v[i - 1], v[i]);
    }
    cout << fabs(ret) << "\n";
    return 0;
}
