#include<cstdio>
#include<algorithm>
int L, C; // L : 사용한 알파벳 종류 수, C : 가능한 알파벳 종류 수
char before = 0; // 오름차순 출력을 위한 변수
char alpha[15 + 1];
bool visit[15 + 1]; // dfs용
char printa[15 + 1]; // 출력할 알파벳 배열
int mocnt, jacnt;
void dfs(int cnt) {
	if (cnt == L) {
		mocnt = jacnt = 0;
		for (int j = 0; j < L; j++) {
			if (printa[j] == 'a' || printa[j] == 'e' || printa[j] == 'i' || printa[j] == 'o' || printa[j] == 'u') {
				mocnt++;
			}
			else jacnt++;
		}
		if (mocnt < 1 || jacnt < 2) return;
		else {
			for (int j = 0; j < L; j++) {
				printf("%c", printa[j]);
			}
			puts("");
			return;
		}

	}
	for (int i = 0; i < C; i++) {
		if (!visit[i] && alpha[i]>before) { // before : 오름차순을 위한 이전 알파벳과 비교
			visit[i] = true;
			printa[cnt] = alpha[i];
			dfs(cnt + 1);
			before = alpha[i];
			visit[i] = false;
		}
	}
}
int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) 
		scanf(" %c", &alpha[i]);
	std::sort(alpha, alpha + C);
	dfs(0);
	return 0;
}