#include<cstdio>
#define MAX (1000+3)
int n;
long long x,len;
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
	while (scanf("%d", &n) != EOF) {
		x = len = 1;
		while (1) {
			if (x%n == 0) {
				printf("%lld\n", len);
				break;
			}
			x *= 10;
			x += 1;
			x %= n;
			len++;
		}
	}
}