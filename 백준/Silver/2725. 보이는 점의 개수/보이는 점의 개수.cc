#include<cstdio>
#define MAX (1000+3)
int C,N, div,input;
int cnt[MAX];
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	int num=0;
	cnt[1] = 3;
	for (int i = 2; i < MAX; i++) {
		num = 0;
		for (int j = 1; j <i; j++) {
			if (gcd(j, i) == 1) {
				num++;
			}
		}
		cnt[i] = cnt[i - 1] + 2 * num;
	}
	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d", &input);
		printf("%d\n", cnt[input]);
	}
}