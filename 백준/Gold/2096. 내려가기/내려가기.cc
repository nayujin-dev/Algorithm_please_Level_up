#include <cstdio>
#include <algorithm>
#include<climits>
int N, a,b,c;
int dpMax[3], dpMin[3];
int m[3], M[3];
int main() {
	scanf("%d", &N);
	scanf("%d %d %d", &dpMax[0], &dpMax[1], &dpMax[2]);
	dpMin[0] = dpMax[0], dpMin[1] = dpMax[1], dpMin[2] = dpMax[2];
	for (int i = 1; i < N;i++) {
		scanf("%d %d %d", &a, &b, &c);
		M[0] = std::max(dpMax[0],dpMax[1]) + a;
		M[1] = std::max(std::max(dpMax[0], dpMax[1]),dpMax[2]) + b;
		M[2] = std::max(dpMax[2], dpMax[1]) + c;
		m[0] = std::min(dpMin[0], dpMin[1]) + a;
		m[1] = std::min(std::min(dpMin[0], dpMin[1]),dpMin[2]) + b;
		m[2] = std::min(dpMin[2], dpMin[1]) + c;
		dpMax[0] = M[0], dpMax[1] = M[1], dpMax[2] = M[2];
		dpMin[0] = m[0], dpMin[1] = m[1], dpMin[2] = m[2];
		// 테스트용 출력
		//printf("max\n");
		//printf("%d %d %d", dpMax[0], dpMax[1], dpMax[2]);
		//printf("\nmin\n");
		//printf("%d %d %d", dpMin[0], dpMin[1], dpMin[2]);
		//puts("");
	}

	printf("%d %d", std::max(std::max(dpMax[0], dpMax[1]), dpMax[2]), std::min(std::min(dpMin[0], dpMin[1]), dpMin[2]));
	return 0;
}