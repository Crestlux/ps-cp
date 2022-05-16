#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i; j < N - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = N - 1; i >= 1; i--) {
        cout << " ";
    }
    cout << "*\n";
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i; j < N - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
