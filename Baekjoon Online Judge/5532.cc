#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    double L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    cout << L - max(ceil(A / C), ceil(B / D)) << "\n";
    return 0;
}
