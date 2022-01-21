#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, consecutive = 0, ret = 665, cnt = 0; bool chkcon = false;
    cin >> N;
    while (1) {
        int temp = ret, prev;
        while (temp > 0) {
            prev = temp % 10;
            if (prev == 6) ++consecutive;
            else consecutive = 0;
            if (consecutive >= 3) chkcon = true;
            temp /= 10;
        }
        if (chkcon) cnt++;
        if (cnt == N) break;
        ret++;
        chkcon = false; consecutive = 0;
    }
    cout << ret << "\n";
    return 0;
}
