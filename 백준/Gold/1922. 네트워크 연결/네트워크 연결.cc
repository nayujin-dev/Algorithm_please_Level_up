#include<cstdio>
#include<algorithm>
int N, M, a,b,c;
int AL[1000 + 1];
int min,cnt;
//나는 크루스칼 알고리즘 쓸랭
int find(int a) {
	if (AL[a] == a) return a;
	return AL[a] = find(AL[a]);
}
void join(int a, int b) {
	int parentA = find(a), parentB = find(b);
	AL[parentA] = parentB;
	return;
}
struct ad {
	int a, b, c;
	const inline bool operator<(const ad &ref) const { //정렬을 위함. 프로님은 const많이 씀 왜냐면 안바뀌게하려구
		return this->c < ref.c;
	}
}Edge[100000+1];
int main(){
	scanf("%d %d", &N, &M);

	//서로소 집합 세팅
	for (int i = 1; i <= N; i++)
		AL[i] = i;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &Edge[i].a, &Edge[i].b, &Edge[i].c); // 비용 입력받기
	}

	//Edge 오름차순 sort
	std::sort(Edge, Edge + M);

	min = cnt = 0;
	//간선 가중치 작은거부터 반복문 돌며, 정점 연결해줌
	for (int i = 0; i < M; i++) { //간선갯수=정점수-1
		if (cnt == N - 1)
			break;
		if (find(Edge[i].a) == find(Edge[i].b)) { //'단순'경로
			continue;
		}
		join(Edge[i].a, Edge[i].b);
		min += Edge[i].c;
		cnt++;
	}
	printf("%d", min);
	return 0;
}