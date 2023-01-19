#include<cstdio>
int N, M,curr;
int x1,y1,x2,y2;
int t[1024 + 1][1024 + 1];
int nSum = 0;
int tot=0;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &curr);
			t[i][j] = curr+ t[i-1][j]+t[i][j-1]-t[i-1][j-1];
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", t[x2][y2] - t[x2][y1 - 1] - t[x1 - 1][y2] + t[x1 - 1][y1 - 1]);
	}
	return 0;
}