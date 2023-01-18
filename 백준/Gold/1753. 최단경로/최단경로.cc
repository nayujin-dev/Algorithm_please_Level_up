#include<cstdio>
#include<climits>//INT_MAX
#include<vector>
#include<queue>
int V, E, K;
//프로님은 pair 잘 안씀. 자유롭게하는거 좋아해서 구조체 씀
struct n_t { //node
	//struct와 class의 차이 : class는 접근제어자가 기본이 private이고, struct는 public이라는 차이점만 존재. 나머진 동일
	int node, cost;
	inline bool operator < (const n_t& ref) const { //c++에서는 heap 기본으로 maxheap 사용
		return this->cost > ref.cost; //cost 작은걸
	}
};
std::vector<n_t> AL[20001];
int visited[20001]; //각 정점에 대한 최단 경로 비용을 저장 (매우 큰 값인경우 미방문)

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AL[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) visited[i] = INT_MAX;

	// Dijkstra
	std::priority_queue<n_t> PQ;
	visited[K] = 0;
	PQ.push({ K,0 });
	while (!PQ.empty()) {
		n_t curr = PQ.top();
		PQ.pop();
		for (n_t next : AL[curr.node]) {
			int cost = visited[curr.node] + next.cost;
			if (cost < visited[next.node]) { //미방문 정점 확인
				visited[next.node] = cost; //좀더 최적화를 위한것임. 굳이 안해도됨
				//방문했을때 갱신하는게 아니라, 방문할 예정일때 visited에 묻혀놓기 
				//-> pq에 의미없는 값이 들어가는것과 판단 로직 횟수를 경감해줌
				PQ.push({ next.node,cost });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == INT_MAX)
			puts("INF");
		else printf("%d\n", visited[i]);
	}
}