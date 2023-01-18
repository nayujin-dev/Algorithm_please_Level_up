#include <cstdio>
const int INF = 1987654321;
inline int MIN(int a, int b) { return a < b ? a : b; }
int N, M; //N: 정점 ~100, M: 간선갯수 ~100000
//인접행렬 --> 최단경로의 비용들이 저장되는곳
int AM[101][101];
int main() {
	scanf("%d %d", &N, &M);
	//초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) AM[i][j] = INF;
		}
	}

	//간선 정보 받기
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		AM[a][b] = MIN(AM[a][b], c);
	}

	//플로이드 워셜 돌리기
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(AM[i][k]!=INF && AM[k][j]!=INF)
					AM[i][j] = MIN(AM[i][j], AM[i][k] + AM[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", AM[i][j] == INF ? 0 : AM[i][j]);
		}
		puts(""); //문자열 출력후 줄바꿈
	}


}