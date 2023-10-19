#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<pair<int,int>> q;
bool visited[100000 + 1];
int n[2] = {1,-1};

int bfs(int first, int initial) {
	q.push({ first, initial });
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		if (x == K) {
			return time;
		}

		for (int i = 0; i < 2; i++) {
			int num = n[i];
			if (x + num <= 100000&& x+num>=0 && !visited[x + num]) {
				q.push({ x + num,time + 1 });
				visited[x + num] = true;
			}
		}
		if (x*2 <= 100000 && !visited[x * 2]) {
			q.push({ x * 2,time + 1 });
			visited[x * 2] = true;
		}
		
		q.pop();
	}
}

int main() {
	cin >> N >> K;
	cout<<bfs(N,0);
	return 0;
}