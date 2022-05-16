#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int R, C, A, B;
	cin >> R >> C >> A >> B;
	vector<char> c1(B, '.'), c2(B, 'X');
	for (int y = 0; y < R; y++) {
		for (int i = 0; i < A; i++) {
			for (int x = 0; x < C; x++) {
				if ((y + x) & 1)
					for (const auto& ele : c1) cout << ele;
				else
					for (const auto& ele : c2) cout << ele;
			}
			cout << "\n";
		}
	}
	return 0;
}
