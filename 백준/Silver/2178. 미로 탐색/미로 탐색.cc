
#include <iostream>
#include <vector>
#include <queue>

int n, m;
bool visit[100 + 2][100 + 2];
int arr[100 + 2][100 + 2];
int maze[100 + 2][100 + 2];

std::string s[100+2];
std::queue<std::pair<int,int>> q;


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1,};

void bfs() {
	q.push({ 0, 0 });
	maze[0][0] = 1;
	int x, y;
	visit[0][0] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] != 0) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					q.push({ nx,ny });
					maze[nx][ny] = maze[x][y] + 1;
				}
				visit[nx][ny] = true;

			}
		}
		q.pop();
	}
}

int main() {
	std::cin >> n >> m;
	std::string s;
	for (int i = 0; i < n; i++) {
		std::cin >> s;

		for (int j = 0; j < m; j++) {
			arr[i][j]=s[j] - '0';
		}
	}

	bfs();
	std::cout << maze[n - 1][m - 1];

	return 0;
}
