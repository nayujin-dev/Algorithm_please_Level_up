#include<cstdio>
int n,tri[500+1][500+1];
int tot[500 + 1][500 + 1];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	int bigger;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				tot[i][j] = tri[i][j] + tot[i - 1][j];
			}
			else if(j == i)
				tot[i][j] = tri[i][j] + tot[i - 1][j-1];
			else {
				bigger = tot[i - 1][j] > tot[i - 1][j - 1] ? tot[i - 1][j] : tot[i - 1][j - 1];
				tot[i][j] = bigger + tri[i][j];
			}
		}
	}
	int maxtot=0;
	for (int j = 1; j <= n; j++) {
		if (maxtot < tot[n][j])
			maxtot = tot[n][j];
	}
	printf("%d", maxtot);
	return 0;
}