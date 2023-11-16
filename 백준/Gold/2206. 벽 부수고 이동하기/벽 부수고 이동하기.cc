#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> dot;
queue<pair<int,int>> crush;
int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0,-1};
int N, M, arr[1000+1][1000+1];
bool visit[1000 + 1][1000 + 1][2];


void bfs() {
	int nx = 0, ny = 0;
	int x=0, y=0,min=1,crushed=0;
	while (!dot.empty()) {
		x = dot.front().first;
		y = dot.front().second;
		min= crush.front().first;
		crushed = crush.front().second;
		dot.pop();
		crush.pop();
		if (x == N - 1 && y == M - 1) break;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visit[nx][ny][crushed]) continue;
			if (crushed == 0 && arr[nx][ny] == 0) {
				crush.push({ min + 1,crushed });
				dot.push({ nx,ny });
				visit[nx][ny][0] = true;
			}
			else if (crushed == 0 && arr[nx][ny] == 1) {
				crush.push({ min + 1,crushed + 1 });
				dot.push({ nx,ny });
				visit[nx][ny][0] = true;
			}
			else if (crushed == 1 && arr[nx][ny] == 0) {
				crush.push({ min + 1,crushed });
				dot.push({ nx,ny });
				visit[nx][ny][1] = true;
			}
			else continue;	
		}
	}
	if (x == N - 1 && y == M - 1) printf("%d", min);
	else printf("-1");
	return;
	
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	dot.push({ 0,0 });
	crush.push({ 1,0 });
	bfs();
	return 0;
}