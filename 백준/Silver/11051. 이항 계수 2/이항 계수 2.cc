#include<iostream>

using namespace std;
long long combi[1001][1001];
int main() {
	int n, k, an;
	an = 1;
	scanf("%d %d", &n, &k);

	//초기화 ->이방향으로 다 1로 초기화 됨
	combi[0][0] = combi[1][0] = combi[1][1] = 1;

	//파스칼 삼각형
	for (int i = 2; i <=n ; i++) {
		for (int j = 0; j <= i; j++) {
			if(j==0||j==i)
				combi[i][j] = 1;
			else {
				combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j])%10007;
			}
		}
	}

	printf("%lld", combi[n][k]);
	return 0;
}