#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    cout << max(A + B, A - B) << "\n" << min(A + B, A - B) << "\n";
    return 0;
}
