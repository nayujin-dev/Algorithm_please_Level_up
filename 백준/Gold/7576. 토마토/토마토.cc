#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m, arr[1000+1][1000+1], day=0;
int dx[4] = {1,-1,0,0};
int dy[4] = { 0,0,1,-1 };
queue <pair< pair<int, int >,int> > q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		day = max(day, cnt);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (arr[ny][nx] == 0) {
				q.push({ {ny,nx},cnt + 1 });
				arr[ny][nx] = 1;
			}
		}
	}
	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ {i,j},0 });
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;

	return 0;
}