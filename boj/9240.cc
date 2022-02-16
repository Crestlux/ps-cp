#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
pll operator-(pll a, pll b) {
    return { a.first - b.first, a.second - b.second };
}
int CCW(const pll &x, const pll &y, const pll &z) {
    double ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
ll dist(const pll &a, const pll &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pll> v(N); vector<pll> st;
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), [&](const pll a, const pll b) {
        if (a.second == b.second) return a.first < b.first; else return a.second < b.second; });
    sort(v.begin() + 1, v.end(), [&](const pll a, const pll b) {
        double deg_a = atan2(a.second - v[0].second, a.first - v[0].first);
        double deg_b = atan2(b.second - v[0].second, b.first - v[0].first);
        if (deg_a < deg_b) return true;
        else if (fabs(deg_a - deg_b) < 1e-14) {
            return dist(v[0], a) < dist(v[0], b);
        }
        else return false; });
    st.push_back(v[0]);
    st.push_back(v[1]);
    int idx = 2; pll next = v[idx];
    while (idx != N) {
        while (st.size() >= 2) {
            pll first, second;
            second = st.back();
            st.pop_back();
            first = st.back();
            next = v[idx];
            if (CCW(first, second, next) > 0) {
                st.push_back(second);
                break;
            }
        }
        st.push_back(next);
        idx++;
    }
    int st_size = st.size();
    ll pl = 0, pr = 0, ret = 0;
    for (int i = 0; i < st_size; i++) {
        if (st[pl].first > st[i].first) pl = i;
        if (st[pr].first < st[i].first) pr = i;
    }
    ret = dist(st[pl], st[pr]);
    for (int i = 0; i < (st_size << 1); i++) {
        if (CCW({ 0,0 }, st[(pl + 1) % st_size] - st[pl], st[pr] - st[(pr + 1) % st_size]) > 0) pl = (pl + 1) % st_size;
        else pr = (pr + 1) % st_size;
        ret = max(ret, dist(st[pl], st[pr]));
    }
    cout << fixed; cout.precision(9);
    cout << static_cast<double>(sqrt(ret)) << "\n";
    return 0;
}
