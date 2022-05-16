#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pdd = pair<double, double>;
int CCW(const pdd &x, const pdd &y, const pdd &z) {
    double ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int case_cnt = 1;
    while (1) {
        int N; double ret = 1e18;
        cin >> N;
        if (N == 0) break;
        vector<pdd> v(N); vector<pdd> st;
        for (int i = 0; i < N; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), [&](const pdd a, const pdd b) {if (fabs(a.second - b.second) < 1e-14) return a.first < b.first; else return a.second < b.second; });
        sort(v.begin() + 1, v.end(), [&](const pdd a, const pdd b) {
            double deg_a = atan2(a.second - v[0].second, a.first - v[0].first);
            double deg_b = atan2(b.second - v[0].second, b.first - v[0].first);
            if (deg_a < deg_b) return true;
            else if (fabs(deg_a - deg_b) < 1e-14) {
                function<double(const pdd, const pdd)> pdist2 = [&](const pdd a, const pdd b) {
                    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
                };
                return pdist2(v[0], a) < pdist2(v[0], b);
            }
            else return false;
        });
        st.push_back(v[0]);
        st.push_back(v[1]);
        int idx = 2; pdd next = v[idx];
        while (idx != N) {
            while (st.size() >= 2) {
                pdd first, second;
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
        int st_size = st.size(), lin = st.size() - 1;
        for (int i = st_size - 1; i >= 1; i--) {
            if (CCW(st[0], st[lin], st[lin - 1]) == 0) lin--;
            else break;
        }
        reverse(st.begin() + lin, st.end());
        function<double(const pdd, const pdd, const pdd)> dist = [&](const pdd p, const pdd q, const pdd r) {
            double a = p.second - q.second, b = q.first - p.first, c = p.first * q.second - p.second * q.first;
            if (a == 0) return fabs((b * r.second) + c) / fabs(b);
            else if (b == 0) return fabs((a * r.first) + c) / fabs(a);
            else return fabs((a * r.first) + (b * r.second) + c) / sqrt(a * a + b * b);
        };
        for (int i = 0; i < st_size; i++) {
            double temp_dist = 0.0;
            for (int j = 0; j < st_size; j++) {
                temp_dist = max(dist(st[i % st_size], st[(i + 1) % st_size], st[j]), temp_dist);
            }
            ret = min(ret, temp_dist);
        }
        cout << fixed; cout.precision(2);
        cout << "Case " << case_cnt++ << ": " << ceil(ret * 100) / 100 << "\n";
    }
    return 0;
}
