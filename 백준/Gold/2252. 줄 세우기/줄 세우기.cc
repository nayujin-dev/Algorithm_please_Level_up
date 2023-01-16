#include<cstdio>
#include<vector>
#include<queue>
//
//using namespace std;
int n, m,a,b;
int inde[32000 + 1];//indegree
int answer[32000 +1];//순서 출력용
std::vector<int> li[32000 + 1]; //인접리스트

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) { 
		scanf("%d %d", &a, &b);
		inde[b]++; //indegree 값 설정
		li[a].push_back(b); //인접리스트 생성
	}
	std::queue<int> arr; //DAG 큐

	for (int j = 1; j <= n; j++) {
		if (!inde[j]) arr.push(j); //인디그리 0인애들 다 넣기
	}


	int k = 0;

	while(!arr.empty()) { //DAG 큐 빌때까지
		int thisS = arr.front();
		arr.pop();
		answer[k++] = thisS;
		for (int next : li[thisS]) {
			if (--inde[next] == 0) arr.push(next);
		}
	}
	for (int j = 0; j < n; j++) {
		printf("%d ", answer[j]);
	}

	return 0;
}