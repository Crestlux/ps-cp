#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" ");
		}
		for (int k = N - i; k > 0; k--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
