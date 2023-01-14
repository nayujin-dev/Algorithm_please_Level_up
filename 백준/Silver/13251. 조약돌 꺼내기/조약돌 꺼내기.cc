#include <cstdio>

#define MAX (50+3)

using namespace std;

int M, K;	// M - 조약돌 색상 종류 / K - 랜덤뽑기 개수

double stoneByColor[MAX];
double percent[MAX];

double total, ans;
int cnt;


int main() {
	// 1. 입력
	//freopen("input.txt", "r", stdin);
	scanf("%d", &M);

	// 2. 컬러별 돌 개수 입력받을때 전체 개수 카운트
	int input;
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		stoneByColor[i] = (double)input;
		total += stoneByColor[i];
	}

	// 3. 확률 계산
	scanf("%d", &K);
	double tmp;
	for (int i = 0; i < M; i++) {
		
		// ** 예외 조건 
		if (stoneByColor[i] < K) continue;

		tmp = 1.0;
		for (int j = 0; j < K; j++) {
			tmp *= (stoneByColor[i] - j) / (total - j);
		}
		percent[i] = tmp;
	}

	for (int i = 0; i < M; i++) {
		ans += percent[i];
	}
	
	// 4. 출력 10-9까지 허용
	printf("%.11lf", ans);
	return 0;
}
