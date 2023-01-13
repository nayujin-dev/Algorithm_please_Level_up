#include<iostream>

using namespace std;
long long combi[1001][1001];
void pas(int n) {
	//초기화 ->이방향으로 다 1로 초기화 됨
	combi[0][0] = combi[1][0] = combi[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				combi[i][j] = 1;
			else {
				combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
			}
		}
	}
}
int main() {
	int t,n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		pas(m);
		printf("%lld\n", combi[m][n]);
	}
	return 0;
}