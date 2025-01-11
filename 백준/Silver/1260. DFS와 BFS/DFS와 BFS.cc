
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

bool visit[1000 + 2];

std::vector<int> v_dfs;
std::vector<int> v_bfs;
std::vector<int> v[1000+2];

void dfs(int thisv) {
	visit[thisv] = true;
	v_dfs.push_back(thisv);

	for (int i = 0; i <v[thisv].size(); i++) {
		if (!visit[v[thisv][i]]) {
			dfs(v[thisv][i]);
		}
	}
	return;
}

void bfs(int thisv) {
	std::queue<int> q;
	q.push(thisv);
	visit[thisv] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		v_bfs.push_back(x);

		for (int i = 0; i < v[x].size(); i++) {
			if (!visit[v[x][i]]) {
				q.push(v[x][i]);
				visit[v[x][i]] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	int a, b;
	std::cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V);
	for (int i = 0; i < v_dfs.size(); i++) {
		std::cout << v_dfs[i] << ' ';
	}
	std::cout << std::endl;
	memset(visit, false, 1000 + 2);
	
	bfs(V);

	for (int i = 0; i < v_bfs.size(); i++) {
		std::cout << v_bfs[i] << ' ';
	}

	std::cout << std::endl;

	return 0;
}
