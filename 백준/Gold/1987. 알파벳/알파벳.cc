#include <iostream>
#include <cmath>

using namespace std;

int R, C, answer=0;
char arr[20 + 1][20 + 1];
bool visit[30];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y,int tot) {
	answer = max(answer, tot);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
			int alpha = arr[ny][nx] - 'A';
			if (!visit[alpha]) {
				visit[alpha] = true;
				dfs(nx, ny, tot + 1);
				visit[alpha] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	visit[arr[0][0]-'A'] = true;
	dfs(0,0,1);

	cout << answer;
	return 0;
}