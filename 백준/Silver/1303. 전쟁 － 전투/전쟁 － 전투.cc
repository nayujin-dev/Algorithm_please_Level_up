
#include <iostream>


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0,-1 };
int arr[100 + 2][100 + 2];
bool visit[100 + 2][100 + 2];

int n, m;
char soldier;
int sumW = 0;
int sumB = 0;

int tot = 1;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
			if (nx < m && ny < n && nx >= 0 && ny >= 0) {
				if (!visit[nx][ny]&&arr[x][y] == arr[nx][ny]) {
					tot++;
					visit[nx][ny] = true;
					dfs(nx, ny);
				}
		}	
	}
	return;
}

int main() {
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> soldier;
			if (soldier == 'W')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				tot = 1;
				dfs(i, j);
				if (arr[i][j] == 0)sumW += tot * tot;
				else sumB += tot * tot;
			}
		}
	}
	std::cout << sumW << " " << sumB << std::endl;

	return 0;
}
