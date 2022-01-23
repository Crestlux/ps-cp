#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int X, Y;
        cin >> X >> Y;
        X < Y ? cout << "NO BRAINS\n" : cout << "MMM BRAINS\n";
    }
    return 0;
}
