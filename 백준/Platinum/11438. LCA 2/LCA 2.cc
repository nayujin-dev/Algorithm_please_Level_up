#include<cstdio>
#include<vector>
#include<deque>
// 1. Depth를 맞춘다
// 2. 부모쪽으로 동시에 같은 간격으로 진행하면서 최소공통조상을 찾는다
int N, M, Depth[100001];
int Par[18][100001]; //계산기 사용해서 찾은 sparse table (부모노드 정보)
std::vector<int> AL[100001];
int main() {
	scanf("%d", &N);
	int a, b;
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		AL[a].push_back(b);
		AL[b].push_back(a); //뭐가 부모인지 모르니까 일단은 서로에게 둘다 추가
	}
	//Depth 구하기 - DFS 혹은 BFS를 이용해서 구한다. (프로님은 BFS)
	std::deque<int> queue; //DFS는 스택, bfs큐인데 걍 한번에 가능한 디큐 쓰심
	queue.push_back(1);
	while (!queue.empty()) {
		int curr = queue.front();
		queue.pop_front();
		for (int next : AL[curr]) {
			//next 가 curr의 부모노드가 아니면 BFS 탐색을 진행.
			if (next != Par[0][curr]) {
				//if문이 맞다면, next는 curr의 자식노드임
				Par[0][next] = curr; //spase table의 0번지 작성 : 사실 이for문은 BFS를 위한건데, 겸사겸사 par도 초기화
				Depth[next] = Depth[curr] + 1; //현재 깊이 +1;
				queue.push_back(next);
			}
		}
	}
	//sparse table 작성(현재는 0번지만 작성되어있음)
	for (int i = 1; i < 18; i++) { //0까지는 작성되어있으므로 1부터
		for (int j = 1; j <= N; j++) {
			Par[i][j] = Par[i - 1][Par[i - 1][j]];
		}
	}

	//test case 받기
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		//1. depth맞추기
		if (Depth[a] < Depth[b]) {
			int tmp = a;
			a = b; 
			b = tmp; //swap! swap할때는 tmp써라
		} // 항상 depth는 a>=b이도록

		  //1-2.  Depth 맞추기
		int diff = Depth[a] - Depth[b];
		//점프해야하는 수를 이진수로 바꾸면,예를들어 13은 1101이므로
		//이진수의 맨 오른쪽 자리에서 시작하여 한칸씩 자리 올리면서 0,1을 판단
		for (int j = 0,mask=1; mask<=diff ; j++,mask<<=1) { //mask의 시프트 연산
			if (diff & mask) a = Par[j][a];
		} //로그스케일

		if (a == b) {
			printf("%d\n", a);
		}
		else {
			//2. LCA 찾기 Depth[a]==Depth[b] 전제됨
			//while (a != b) {
			for (int j = 17; j >= 0; j--) {
				if (Par[j][a] != Par[j][b]) {
					a = Par[j][a];
					b = Par[j][b];
				}
			} //로그스케일
			//sparse table의 0번지부터 시뮬레이션
			//if 16번째 뛰었을때 같으면, 8보다는 많이 뛰고 16번 이하로 뜀. 그럼 그거에 대해 또 시뮬레이션 반복
		//} //로그스케일
			printf("%d\n", Par[0][a]);
		}
	}


	return 0;
}