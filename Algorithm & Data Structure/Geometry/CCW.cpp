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
    return 0;
}
/**/
