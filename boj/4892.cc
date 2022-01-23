#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n0, n1, n2, n3, n4, cnt = 1;
    while (1) {
        cin >> n0;
        if (n0 == 0) break;
        else {
            n1 = 3 * n0;
            if (n1 & 1) n2 = (n1 + 1) / 2;
            else  n2 = n1 / 2;
            n3 = 3 * n2;
            n4 = n3 / 9;
        }
        (n1 & 1) ? cout << cnt << ". odd " << n4 << "\n" : cout << cnt << ". even " << n4 << "\n";
        cnt++;
    }
    return 0;
}
