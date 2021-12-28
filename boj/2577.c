#include <stdio.h>
 
int main() { 
	int A, B, C, num, len = 0;
	int arr[10];
	int ans[10] = { 0, };
	scanf("%d %d %d", &A, &B, &C);
	num = A * B * C;
	while (num > 0) {
		num /= 10;
		len++;
	}
	num = A * B * C;
	for (int i = 0; i < len; i++) {
		arr[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i] == j) {
				ans[j]++;
				break;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
