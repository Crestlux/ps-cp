#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int CCW(const pll &x, const pll &y, const pll &z) {
    ll ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<pll, char>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    function<ll(pll, pll)> dist = [&](const pll a, const pll b) {
        ll dx = a.first - b.first;
        ll dy = a.second - b.second;
        return dx * dx + dy * dy;
    };
    sort(v.begin(), v.end(), [&](const pair<pll, char> a, const pair<pll, char> b) {
        if (fabs(a.first.first - b.first.first) < 1e-14) return a.first.second < b.first.second;
        else return a.first.first < b.first.first; });
    sort(v.begin() + 1, v.end(), [&](const pair<pll, char> a, const pair<pll, char> b) {
        double deg_a = atan2(a.first.second - v[0].first.second, a.first.first - v[0].first.first);
        double deg_b = atan2(b.first.second - v[0].first.second, b.first.first - v[0].first.first);
        if (deg_a < deg_b) return true;
        else if (fabs(deg_a - deg_b) < 1e-14) { return dist(v[0].first, a.first) < dist(v[0].first, b.first); }
        else return false; });
    v.erase(remove_if(v.begin(), v.end(), [&](pair<pll, char> a) {return a.second == 'N'; }), v.end());
    int v_size = v.size(), lin = v.size() - 1;
    for (int i = v_size - 1; i >= 1; i--) {
        if (CCW(v[0].first, v[lin].first, v[lin - 1].first) == 0) lin--;
        else break;
    }
    reverse(v.begin() + lin, v.end());
    cout << v.size() << "\n";
    for (const auto &e : v) {
        cout << e.first.first << " " << e.first.second << "\n";
    }
    return 0;
}
