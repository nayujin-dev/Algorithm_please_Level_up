#include <iostream>

int pan[5][5];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int tot = 0;
bool num[999999 + 1];

void dfs(int x, int y, int cnt, int n) {

	if (cnt == 5) {
		if (!num[n]) {
			//std::cout << n<<std::endl;
			tot++;
			num[n] = true;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 5 && ny < 5 && nx >= 0 && ny >= 0) {
			if (cnt < 5) {
				dfs(nx, ny, cnt + 1,n*10+pan[nx][ny]);
			}
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> pan[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0,pan[i][j]);
		}
	}

	std::cout << tot;

	return 0;
}
