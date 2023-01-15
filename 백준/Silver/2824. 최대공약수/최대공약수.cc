#include<cstdio>
#define MAX (1000+3)
#define INFIN (1000000000)
int N,M,div;
long long an;
int n[MAX], m[MAX];
bool isLong;
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
	an = 1;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &n[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &m[i]);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (gcd(n[i], m[j]) != 1) {
				div= gcd(n[i], m[j]);
				an *= div;
				n[i] /= div;
				m[j] /= div;
			}
			if (an >= INFIN) {
				an %= INFIN;
				isLong = true;
			}
		}
	}
	if (isLong) {
		printf("%09lld", an);
		return 0;
	}
	printf("%lld", an);
	return 0;
}