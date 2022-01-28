#include <bits/stdc++.h>
using namespace std;
int cnt = 0, N = 0, board[16];
int chkPossible(int idx) {
	for (int i = 0; i < idx; i++) {
		if (board[idx] == board[i] || abs(idx - i) == abs(board[idx] - board[i])) {
			return 0;
		}
	}
	return 1;
}
void nqueen(int idx) {
	if (idx == N) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			board[idx] = i;
			if (chkPossible(idx)) nqueen(idx + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	nqueen(0);
	cout << cnt << "\n";
	return 0;
}
