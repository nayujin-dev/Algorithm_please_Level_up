#include<iostream>
#include<string>
//using namespace std;
int arr[10000];
int pt;
//string arr[10000];
void push(int n) {

	arr[pt++] = n;
}
void pop() {
	if (arr[pt - 1] == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[pt - 1]);
		pt--;
	}
}

void size() {
	printf("%d\n", pt);
}
void empty() {
	if (pt == 0)
		printf("1\n");
	else
		printf("0\n");
}
void top() {
	if (pt == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[pt - 1]);
}
int main(){
	int N,x;
	pt = 0;
	std::string cmd;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		std::cin >> cmd;
		if (cmd.compare("push")==0) {
			scanf("%d", &x);
			push(x);
		}
		else if (cmd.compare("pop") == 0) pop();
		else if (cmd.compare("size") == 0) size();
		else if (cmd.compare("empty") == 0) empty();
		else if (cmd.compare("top") == 0) top();
	}
	return 0;
}