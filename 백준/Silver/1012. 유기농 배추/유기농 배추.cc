#include <iostream>
#include <queue>

int T;
int N, M, K;
bool cabbage[50][50];
std::queue<std::pair<int, int>> queue;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int y,int x) {
	queue.push({ y, x });
	cabbage[y][x] = false;
	while (!queue.empty()) {
		int Y = queue.front().first;
		int X= queue.front().second;
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int newy = Y + dy[i];
			int newx = X + dx[i];
			if (newy < N && newx < M && newy >= 0 && newx >= 0) {
				if (cabbage[newy][newx]) {
					cabbage[newy][newx] = false;
					queue.push({ newy,newx });
				}
			}
		}
	}


	return;
}

int main() {
	std::cin >> T;
	while (T-- > 0) {
		int X, Y;
		int cnt = 0;
		std::cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			std::cin >> X >> Y;
			cabbage[Y][X] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cabbage[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		std::cout << cnt << std::endl;
	}
	return 0;
}