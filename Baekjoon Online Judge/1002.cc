#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T, r1, r2; pair<int, int> A, B; double dst, rsum, rsub;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A.first >> A.second >> r1 >> B.first >> B.second >> r2;
        dst = pow((A.first - B.first), 2) + pow((A.second - B.second), 2);
        rsum = pow((r1 + r2), 2);
        rsub = pow((r1 - r2), 2);
        if (rsum == dst || (rsub == dst && rsub != 0)) { cout << "1\n"; continue; }
        if (rsum > dst && rsub < dst) { cout << "2\n"; continue; }
        if (rsum < dst || rsub > dst || (dst == 0 && r1 != r2)) { cout << "0\n"; continue; }
        if (dst == 0 && r1 == r2) { cout << "-1\n"; continue; }
    }
    return 0;
}
