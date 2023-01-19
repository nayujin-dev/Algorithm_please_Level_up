#include<cstdio>
int N,M,num[100000+1];
int i, j;

int main() {
	int curr;
	scanf("%d %d", &N,&M);
	for (int k = 1; k <= N; k++) {
		scanf("%d", &curr);
		num[k] = curr + num[k - 1];
	}
	for (int k = 1; k <= M; k++) {
		scanf("%d %d", &i,&j);
		printf("%d\n", num[j] - num[i-1]);
	}
	return 0;
}