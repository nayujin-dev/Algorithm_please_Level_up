#include<cstdio>
#define MAX (1000000+3)
int n,a;
bool isNotPrimenumber[MAX];		// true 소수 아님  / false 소수임

int main() {
	for (int i = 2; i * i < MAX; i++)
	{
		if (isNotPrimenumber[i] == false) {
			for (int j = i * i; j < MAX; j += i)
			{
				isNotPrimenumber[j] = true;
			}
		}
	}
	while (1) {
		a = 0;
		scanf("%d", &n);
		//마지막 입력
		if (n == 0)
			return 0;
		for (int i = 3; i <= n / 2; i += 2) {
			if (isNotPrimenumber[i]==false && isNotPrimenumber[n - i]==false) {
				a = i;
				break;
			}
		}
		//출력
		if (a == 0) {
			printf("%s", "Goldbach's conjecture is wrong.\n");
		}
		else {
			printf("%d = %d + %d\n", n, a, n - a);
		}
	}
	return 0;
}