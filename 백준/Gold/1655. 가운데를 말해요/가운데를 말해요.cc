#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,num;
priority_queue<int> pqL; // 최대힙
priority_queue<int, vector<int>, greater<int>> pqR; //최소힙

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		
		if (i == 1) {
			pqR.push(num);
			cout << num << "\n";
			continue;
		} 

		if (i % 2 == 0) { // 현재까지 들어온 수 짝수개일때
			int r = pqR.top();
			if (num >r) {
				pqR.pop();
				pqL.push(r);
				pqR.push(num);
			}
			else {
				pqL.push(num);
			}
			int l = pqL.top();
			if (l < r) 
				cout << l << "\n";
			else
				cout << r << "\n";
		}
		else {// 현재까지 들어온 수 홀수개일때
			int l = pqL.top();
			if (num < l) {
				pqL.pop();
				pqR.push(l);
				pqL.push(num);
			}
			else {
				pqR.push(num);
			}
			int r = pqR.top();
			cout << r << "\n";
		}
	}
	return 0;
}