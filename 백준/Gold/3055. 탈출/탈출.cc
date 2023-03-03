#include <cstdio>
#include<queue>

int R, C;
char map[52][52];
int visit[52][52];
int time;
typedef std::pair<int, int>pii;
std::queue<pii> water, gos;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
//비버 D, 고슴도치 S

void bfs() {
	// 1. 사전 처리 - 고슴도치, 물 초기 위치
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') {
				gos.push(pii(i, j));
				visit[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				water.push(pii(i, j));
			}
		}
	}

	// 2. 시간 순으로 확인
	for (time = 1;; time++) {
		int waterSize = water.size();
		for (int i = 0; i < waterSize; i++) {
			pii cur = water.front();
			water.pop();

			// 상하좌우로 퍼지기
			for (int j = 0; j < 4; j++) {
				int nr = cur.first + dr[j];
				int nc = cur.second + dc[j];

				if (nr < 0 || nc < 0 || nr >= R || nc >= C)continue;
				if (map[nr][nc] == '.') {
					map[nr][nc] = '*';
					water.push(pii(nr, nc));
				}
			}
		}

		int gosSize = gos.size();
		if (gosSize == 0) {
			time = -1;
			return;
		}
		for (int i = 0; i < gosSize; i++) {
			pii cur = gos.front();
			gos.pop();

			for (int j = 0; j < 4; j++) {
				int nr = cur.first + dr[j];
				int nc = cur.second + dc[j];

				if (nr < 0 || nc < 0 || nr >= R || nr >= C) continue;
				
				if (map[nr][nc] == 'D') return;
				else if (map[nr][nc] == '.' && visit[nr][nc]==0) {
					visit[nr][nc] = 1;
					gos.push(pii(nr, nc));
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", map[i]);
	}
	
	bfs();

	if (time == -1)
		printf("KAKTUS");
	else
		printf("%d", time);
	
	return 0;
}