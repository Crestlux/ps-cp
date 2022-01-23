#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[41];
ll fibonacci(int n) {
	if (dp[n] != -1) return dp[n];
	else { return dp[n] = fibonacci(n - 1) + fibonacci(n - 2); }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	memset(dp, -1, 41*sizeof(ll));
	dp[0] = 0; dp[1] = 1;
	fibonacci(40);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input == 0) cout << "1 0\n";
		else if (input == 1) cout << "0 1\n";
		else cout << dp[input-1] << " " << dp[input] << "\n";
	}
	return 0;
}
