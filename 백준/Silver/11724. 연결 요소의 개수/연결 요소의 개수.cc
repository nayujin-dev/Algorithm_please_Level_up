
#include <iostream>
#include <vector>

int n, m, u, v;
std::vector<int> linkedlist[1000+2];
bool visit[1000+2];
int tot = 0;

void dfs(int i) {
	visit[i] = true;
	for (int j = 0; j < linkedlist[i].size(); j++) {
		int idx = linkedlist[i][j];
		if (!visit[idx]) dfs(idx);
	}
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		linkedlist[u].push_back(v);
		linkedlist[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			tot++;
		}
	}

	std::cout << tot;

	return 0;
}