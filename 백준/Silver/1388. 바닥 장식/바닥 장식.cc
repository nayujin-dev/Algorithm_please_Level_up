#include <iostream>
#include <vector>
int N, M, tot = 0, prev;
char thisPattern;
std::vector<std::vector<int>> pattern;
bool visit[50 + 2][50 + 2];

void dfs(int row, int col) {
	// 탈출 조건
	if (prev != pattern[row][col]) {
		//std::cout << "이전값이랑 달라질때"<<std::endl;
		tot++;
		return;
	}
	if (visit[row][col] == false) {
		visit[row][col] = true;

		if (pattern[row][col] == 0) { //가로무늬
			if (col == M - 1) {
				//std::cout << "테두리일때" << std::endl;
				tot++;
				return;
			}
			prev = pattern[row][col];
			dfs(row, col + 1);
		}else { //세로무늬
			if (row == N - 1) {
				//std::cout << "테두리일때" << std::endl;
				tot++;
				return;
			}
			prev = pattern[row][col];
			dfs(row + 1, col);
		}
	}
	return;
}
int main() {
	// input
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::vector<int> oneline;

		for (int j = 0; j < M; j++) {
			std::cin >> thisPattern;
			if (thisPattern == '-') {
				oneline.push_back(0);
			}
			else if (thisPattern == '|') {
				oneline.push_back(1);
			}
		}
		pattern.push_back(oneline);
	}
	
	// 그래프 탐색, dfs
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]==false) {
				prev = pattern[i][j];
				dfs(i, j);
			}
		}
	}
	std::cout << tot;
	return 0;
}