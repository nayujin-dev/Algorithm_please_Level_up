#include<iostream>
long long M,sum;
int N, high, low, tot;
int arr[10000];
int main() {
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sum = 0;
	high = low = tot = 0;
	while (1) {
		if (sum <= M) {
			if (high > N) break;
			else if (sum == M) tot++;
			sum += arr[high++];
		}
		else if (sum > M) {
			sum -= arr[low++];
		}
	}
	printf("%d", tot);
	return 0;
}