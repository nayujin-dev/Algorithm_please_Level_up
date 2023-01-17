#include<cstdio>
#include<vector>
//#include<set>
int N, M, a, b, an,cnt;
//int indegree[500 + 1], outdegree[500 + 1];
std::vector<int>down[500 + 1];
std::vector<int>up[500 + 1];
//std::set<int>node;
bool visit[500 + 1];

void dfs(int curr,int prev) { //아래로 향하는 dfs
	//if (outdegree[curr] == 0) {
	//	return;
	//}
	if (prev != 0)
		visit[curr] = true;
	for (auto next: down[curr])
	{
		//node.insert(next);
		if (visit[next])
			continue;
		dfs(next,curr);
	}
	return;
}
void rdfs(int curr,int prev) { //윗방향으로 향하는 dfs
	//if (indegree[curr] == 0 ) {
	//	return;
	//}
	if (prev != 0)
		visit[curr] = true;
	for (auto next : up[curr])
	{
		//node.insert(next);
		if (visit[next])
			continue;
		rdfs(next,curr);
	}
	return;
}
int main() {
	an = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		//indegree[b]++;
		//outdegree[a]++;
		down[a].push_back(b);
		up[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			visit[j] = false;
		// 1. 나보다 큰애들 DFS
		dfs(i,0);
		// 2. 나보다 작은애들 DFS
		rdfs(i,0);
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[j])
				cnt++;
		}
		if (cnt + 1 == N)
			an++;
		//if (node.size()+ 1 == N)
		//	an++;
		//node.clear(); //노드 갯수 초기화
	}
	printf("%d",an);
	return 0;
}