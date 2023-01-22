#include<cstdio>
#include<algorithm>
int N, M,num[10000+1];
int pNum[10000 + 1];
bool visit[10000 + 1];
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", pNum[i]);
		}
		printf("\n");
		return;
	}
	int beforeN = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i]==false&&beforeN!=num[i]&&pNum[cnt-1]<=num[i]) {
			visit[i] = true;
			pNum[cnt] = num[i];
			beforeN = num[i];
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	std::sort(num, num + N);
	dfs(0);
	return 0;
}
