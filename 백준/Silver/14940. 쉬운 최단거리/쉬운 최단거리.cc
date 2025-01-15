
#include <iostream>
#include <queue>

std::queue<std::pair<int, int>> q;
int answer[1000 + 2][1000 + 2];
int arr[1000 + 2][1000 + 2];
bool visit[1000 + 2][1000 + 2];
int n, m, num;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs() {
	int x, y;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		visit[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (!visit[ny][nx] && arr[ny][nx] == 1) {
					q.push({ ny,nx });
					answer[ny][nx] = answer[y][x]+1;
				}
				visit[ny][nx] = true;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> num;
			if (num == 2) {
				q.push({ i, j });
			}
			else if (num == 1) {
				arr[i][j] = 1;
				answer[i][j] = -1;
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j])
				std::cout << answer[i][j] << " ";
			else if (arr[i][j] == 0)
				std::cout << "0 ";
			else
				std::cout << "-1 ";
		}
		std::cout << std::endl;
	}

	return 0;
}
