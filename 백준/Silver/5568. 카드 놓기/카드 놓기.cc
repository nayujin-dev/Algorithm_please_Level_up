#include<iostream>
#include<string>
#include<set>

using namespace std;

bool visit[100];
set<string> cardCnt;
int arr[100],n;

void dfs(string num, int cnt) {
	//탈출 조건
	if (cnt == 0)
	{
		cardCnt.insert(num);
		return;
	}
	for (int i=0;i < n;i++)
		//visit 배열확인 후 방문
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			dfs(num + to_string(arr[i]), cnt - 1);
			visit[i] = false;
		}
	}
}
int main() {
	int k;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	
	}
	dfs("", k);
	printf("%d", cardCnt.size());

	return 0;
}