#include <bits/stdc++.h>
using namespace std;
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
    int N;
    cin >> N;
    vector<pdd> v(N); stack<pdd> st;
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](const pdd a, const pdd b) {if (fabs(a.second - b.second) < 1e-14) return a.first < b.first; else return a.second < b.second; });
    sort(v.begin() + 1, v.end(), [&](const pdd a, const pdd b) { if (atan2(a.second - v[0].second, a.first - v[0].first) < atan2(b.second - v[0].second, b.first - v[0].first)) return true; else if (fabs(atan2(a.second - v[0].second, a.first - v[0].first) - atan2(b.second - v[0].second, b.first - v[0].first)) < 1e-14) { if (fabs(a.second - b.second) < 1e-14) return a.first < b.first; else return a.second < b.second; } else return false; });
    st.push(v[0]);
    st.push(v[1]);
    int idx = 2; pdd next = v[idx];
    while (idx != N) {
        while (st.size() >= 2) {
            pdd first, second;
            second = st.top();
            st.pop();
            first = st.top();
            next = v[idx];
            if (CCW(first, second, next) > 0) {
                st.push(second);
                break;
            }
        }
        st.push(next);
        idx++;
    }
    cout << st.size() << "\n";
    return 0;
}
