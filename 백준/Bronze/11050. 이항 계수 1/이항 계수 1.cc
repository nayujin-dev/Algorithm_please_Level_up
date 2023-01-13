#include<iostream>

using namespace std;

int main() {
	int n, k,an;
	an = 1;
	scanf("%d %d", &n, &k);
	for (int i = n; i > n - k; i--) {
		an *= i;
	}
	//printf("%d", an);
	for (int i = 1; i <= k; i++)
		an /= i;
	printf("%d", an);
	//1. n 인풋받기
	//2. 소수 *
	return 0;



}