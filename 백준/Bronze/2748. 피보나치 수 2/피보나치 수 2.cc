#include<iostream>

long long arr[91];
long long an;
void fibo(int num,int level) {
	if (num == 1)
		an= arr[level-1];
	else {
		arr[level] = arr[level-1]+arr[level-2];
		//printf("%d\n", arr[level]);
		fibo(--num, ++level);
	}
}
int main() {
	int n;
	arr[0] = 0;
	arr[1] = 1;
	scanf("%d", &n);
	fibo(n, 2);
	printf("%lld", an);
	return 0;
}