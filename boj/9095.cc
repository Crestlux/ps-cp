#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int dp[11] = { 0, }, arr[] = { 1,2,3 }, n;
	cin >> n;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		for (const auto& c : arr) {
			if (i >= c) dp[i] += dp[i - c];
		}
	}
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		cout << dp[input] << "\n";
	}
	return 0;
}
