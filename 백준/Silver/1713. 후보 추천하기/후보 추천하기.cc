#include <cstdio>
#include<algorithm>
int N, M,thisS;
int photo[20 + 1]; //사진 틀
int recmd[100 + 1]; //추천수
int queueS[1000 + 1]; // 추천하는 횟수
int existNum; // 기존 추천학생일시, 그 학생의 번호
int pt;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &thisS);
		bool isExist = false;
		bool isLeft = false;
		// 1. 기존에 추천된 학생인가?
		for (int j = 0; j < N; j++) {
			if (photo[j] == thisS) {
				isExist = true;
				existNum = photo[j];
				break;
			}
		}
		if (isExist) { // 1-a. 기존 추천 학생일때
			recmd[existNum]++;
		}
		else { // 1-b. 기존 추천 학생 아닐때
			for (int j = 0; j < N; j++) {
				if (photo[j] == 0) {
					pt = j;
					isLeft = true;
					break;
				}
			}
			if (isLeft) { // 1-b-2. 사진틀이 다 안찼을때
				photo[pt] = thisS;
				queueS[i] = thisS;
				recmd[thisS]++;
			}
			else { // 1-b-1. 사진틀이 다 찼을때
				int outN = 0;
				int outQN = 0;
				int minR = 1001; // 최소 추천횟수인 학생을 찾기위한, 최대 추천횟수+1 

				for (int j = 0; j <= i; j++) {
					if (recmd[queueS[j]] < minR && recmd[queueS[j]]!=0) {
						minR = recmd[queueS[j]]; // 최소 추천횟수
						outN = queueS[j]; // 삭제할 학생 번호
						outQN = j; // 시간순 배열에서 삭제할 인덱스
					}
				}
				//printf("빠지게될 학생번호: %d\n", outN);
				queueS[outQN]=0;
				recmd[outN] = 0;
				for (int j = 0; j < N; j++) {
					if (photo[j] == outN) {
						photo[j] = thisS;
						recmd[thisS]++;
						queueS[i] = thisS;
						break;
					}
				}
			}
		}
		// 검토용 출력
		//printf("%d번째 : ", i + 1);
		//for (int k = 0; k < N; k++) {
		//	printf("%d ", photo[k]);
		//}
		//printf("\n");
	}
	std::sort(photo, photo + N);
	for (int i = 0; i < N; i++) {
		if(photo[i]!=0)
			printf("%d ", photo[i]);
	}
}