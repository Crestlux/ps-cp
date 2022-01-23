#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int sum = 0, temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		sum += temp;
	}
	cout << sum << "\n";
	return 0;
}
