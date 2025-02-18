#include <iostream>
#include <vector>
#include <queue>

int n, m, k, ans=0;
bool visit[100 + 2][100 + 2];
int arr[100 + 2][100 + 2];
int maze[100 + 2][100 + 2];

std::string s[100 + 2];
std::queue<std::pair<int, int>> q;


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1, };

void bfs(int r, int c) {
	visit[r][c] = true;
	if (arr[r][c] == 0) {
		return;
	}
	int size = 1;
	q.push({ r,c });
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] != 0) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					q.push({ nx,ny });
					size++;
				}
				visit[nx][ny] = true;

			}
		}
		q.pop();
	}
	if (size > ans) {
		ans = size;
	}
}

int main() {
	std::cin >> n >> m >> k;
	int r, c;
	for (int i = 0; i < k; i++) {
		std::cin >> r >> c;
		arr[r - 1][c - 1] = 1;
		maze[r - 1][c - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bfs(i,j);
		}
	}

	std::cout << ans;

	return 0;
}
