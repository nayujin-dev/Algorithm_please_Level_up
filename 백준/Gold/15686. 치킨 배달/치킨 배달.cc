#include<cstdio>
#include<climits>
#include<vector>
#include<iostream>
int N, M,curr;
std::vector<std::pair<int, int>>chicken;
std::vector<std::pair<int,int>>home;
std::vector<int>distance;

int cal() {
	int sumdistance = 0;
	for (auto h : home) {
		int minch = INT_MAX;
		for (auto ch : chicken) {
			if (ch.first != -1) {
				if (abs(h.first - ch.first) + abs(h.second - ch.second) < minch) {
					minch = abs(h.first - ch.first) + abs(h.second - ch.second); //치킨거리
				}
			}
		}
		sumdistance += minch;
		//printf("치킨거리 : %d\n", sumdistance);
	}
	return sumdistance; // 치킨거리 return
}

void dfs(int idx, int rest) {
	if (rest == 0) { // 폐업 시켜야할 만큼 시킨경우
		distance.push_back(cal());
		return;
	}
	if (idx > chicken.size() - 1) return;
	int backup = chicken[idx].first;
	chicken[idx].first = -1; // 폐업 처리
	dfs(idx + 1, rest - 1);
	chicken[idx].first = backup; // 폐업 아닐때
	dfs(idx + 1, rest);
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &curr);
			if (curr == 2) chicken.push_back({ i,j });
			else if (curr == 1) home.push_back({ i,j });
		}
	}
	dfs(0,chicken.size() - M);// 도시의 치킨거리가 가장 작게 되는 M개의 치킨집을 남기기

	int minD = INT_MAX;
	for (auto d : distance) { // distance 벡터 중 최솟값 찾아 출력
		if (d < minD) {
			minD = d;
		}
	}
	printf("%d", minD);
	return 0;
}