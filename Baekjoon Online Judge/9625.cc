#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int dp[46][2], N;
	cin >> N;
	dp[0][0] = 1; dp[1][0] = 0;
	dp[1][0] = 0; dp[1][1] = 1;
	dp[2][0] = 1; dp[2][1] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	cout << dp[N][0] << " " << dp[N][1] << "\n";
	return 0;
}
