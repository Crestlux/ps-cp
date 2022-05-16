#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, I;
    cin >> N >> I;
    vector<string> s1(N);
    for (int i = 0; i < N; i++) {
        cin >> s1[i];
    }
    sort(s1.begin(), s1.end());
    cout << s1[I - 1] << "\n";
    return 0;
}
