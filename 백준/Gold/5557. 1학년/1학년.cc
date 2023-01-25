#include <cstdio>
int N,curr;
int arr[100 + 2]; // 입력받은 수 배열
long long dp[100 + 2][20 + 2]; // long long이 2^63 -1 까지임

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0][arr[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		curr = arr[i];
		for (int j = 0; j < 21; j++) {
			if (j + curr < 21) {
				dp[i][j] += dp[i - 1][j + curr];
			}
			if (j - curr >= 0) {
				dp[i][j] += dp[i - 1][j - curr];
			}
		}
	}
	printf("%lld", dp[N - 2][arr[N - 1]]);
	return 0;
}