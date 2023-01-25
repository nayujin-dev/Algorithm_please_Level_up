#include <cstdio>
int N, H; // N: 동굴 길이 짝수, H: 동굴 높이
int ob; // 장애물
int OFFSET = 1;
int tree[1100000];
int query(int idx){
	int tot = 0;
	idx += OFFSET;
	while (idx>0) {
		tot += tree[idx];
		idx /= 2;
	}
	return tot;
}
void update(int sidx, int eidx) {
	sidx += OFFSET;
	eidx += OFFSET;
	while (sidx <=eidx) {
		if (sidx % 2 == 1) tree[sidx++]++;
		if (eidx % 2 == 0) tree[eidx--]++;
		sidx /= 2;
		eidx /= 2;
	}
}
int main() {
	scanf("%d %d", &N, &H);
	while (OFFSET < H) OFFSET *= 2;
	OFFSET--;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &ob); // 장애물 input
		if (i % 2 == 1) update(H - ob + 1, H); // 석순일때
		else update(1, ob); //종유석일때
	}

	int min = 500000 + 5;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		int result = query(i);
		if (result < min) {
			min = result;
			cnt = 1;
		}
		else if (result == min) cnt++;
	}
	printf("%d %d", min, cnt);
	return 0;
}
