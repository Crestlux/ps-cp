#include <bits/stdc++.h>
using namespace std;
int main() {
	int C = 0, N = 0;
	scanf("%d", &C);
	vector<double> answer(C);
	vector<int> arr(N);
	for (int i = 0; i < C; i++) {
		int sum = 0, count = 0;
		double average = 0.0;
		scanf("%d", &N);
		arr.resize(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		average = sum / N;
		for (int k = 0; k < N; k++) {
			if (arr[k] > average)	count++;
			else;
		}
		answer[i] = (double(count) / N) * 100;

	}
	for (int j = 0; j < C; j++) {
		printf("%.3lf%%\n", answer[j]);
	}
	return 0;
}
