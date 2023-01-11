#include<iostream>
#include <queue>

using namespace std;
int n;
struct node {
	int value;
	node(int a) {
		value = a;
	}
	//value의 내림차순 정렬
	bool operator < (const node& o) const {
		return value < o.value;// <의 방향이 윗줄 아랫줄 같도록.
		//오름차순으로 하려면 ? return문의 부등호 방향을 반대로
	}

};
priority_queue <node> pq;

int main() {
	int N,x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x != 0) pq.push(x);
		else {
			if (pq.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}