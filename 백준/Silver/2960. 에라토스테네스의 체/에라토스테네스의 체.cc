#include <cstdio>

#define MAX (1000+3)

using namespace std;

bool isNotPrimenumber[MAX];	// 기본값 false
int N, K;

int main() {
	// 1. 입력받는다
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);

	// 2. 에라토스테네스의 체
	int cnt = 0;	// 지운 횟수 카운트
	for (int i = 2; i <= N; i++) {

		// 1) 이미 지워졌으면 pass
		if (isNotPrimenumber[i] == true) {
			continue;
		}

		// 2) 배수 제거
		for (int j = i; j <= N; j += i) {
			if (isNotPrimenumber[j] == false) {

				isNotPrimenumber[j] = true;
				cnt++;
				
				// K번째 지우는 순간 출력
				if (cnt == K) {
					printf("%d", j);
					return 0;
				}

			}
		}

	}
	
	return 0;
}