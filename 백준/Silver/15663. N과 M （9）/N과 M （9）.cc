#include<cstdio>
#include<algorithm>
int N, M,n;
int num[10000 + 1];
int pnum[10000 + 1];
bool visit[10000 + 1];
void dfs(int idx) {
	if (idx == M) {
		for(int i=0;i<M;i++){
			printf("%d ", pnum[i]);
		}
		printf("\n");
		return;
	}

	int check = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i]&&check!=num[i]) {
			pnum[idx] = num[i];
			check = pnum[idx];
			visit[i] = true;
			dfs(idx+1);
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