#include<cstdio>
#include<algorithm>
#define MAX (100000)
using namespace std;

int N, M,a[MAX+3],num;
int left,right, mid;

int bSearch(int num) {
	left=0;
	right = N-1;
	while (left<=right) {
		mid = (left + right) / 2;
		if (a[mid] == num) {
			return 1;
		}
		else if (a[mid] > num) {
			right = mid - 1;
		}
		else if (a[mid] < num) {
			left = mid + 1;
		}
	}
	
	//for(int)
	return 0;
}
int main() {
	//1. n 인풋받기
	scanf("%d", &N);
	//2. 배열에 저장하기 & 정렬
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	//3. m 인풋 받기
	scanf("%d", &M);
	//4. 유무 판정 by 이진탐색
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		printf("%d\n",bSearch(num));
	}
	return 0;
}