#include<cstdio>
#include<algorithm>
int n;
int point[300 + 1];
int score[300 + 1];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &point[i]);
		score[i] = point[i];
	}
	
	score[1] = point[1];
	score[2] = point[2] + point[1];

	for (int i = 3; i <= n; i++) {
		score[i] = std::max(score[i - 2] + point[i], score[i - 3] + point[i - 1] + point[i]);
	}
	printf("%d", score[n]);
	return 0;
}