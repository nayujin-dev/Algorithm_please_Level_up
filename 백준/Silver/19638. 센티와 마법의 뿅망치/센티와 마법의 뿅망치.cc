#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

priority_queue<int> pq;
int N, T,tot=0;
long long H,h;

int main() {
	cin >> N >> H >> T;
	for (int i = 0; i < N; i++) {
		cin >> h;
		pq.push(h);
	}

	for (; tot < T; tot++) {
		if (pq.top() < H) break;
		long long thisH=pq.top();
		if (thisH == 1) continue;
		pq.pop();
		pq.push(floor(thisH / 2));
	}
	if (pq.top() >= H) 
		cout << "NO" <<endl<< pq.top();
	else
		cout << "YES" << endl << tot;
	return 0;
}