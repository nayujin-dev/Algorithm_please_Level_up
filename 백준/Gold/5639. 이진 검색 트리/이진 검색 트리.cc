#include <cstdio>
int N;
int arr[10000 + 2];

void postOrder(int sPt,int ePt){
	if (sPt>=ePt) {
		return;
	}
	int i;
	for (i = sPt + 1; i < ePt; i++) {
		if (arr[sPt] < arr[i]) break;
	}
	postOrder(sPt + 1, i);
	postOrder(i, ePt);
	printf("%d\n", arr[sPt]);
	return;
}
int main() {
	int i = 0;
	while (scanf("%d", &N) > 0) {
		arr[i++] = N;
	}
	postOrder(0,i); // root부터 모든 노드 후위탐색으로 출력
	return 0;
}