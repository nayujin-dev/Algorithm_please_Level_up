#include<iostream>
#include<string>
//using namespace std;
int arr[10000];
int spt,ept;
void push(int n) {

	arr[ept++] = n;
}
void pop() {
	if (ept== spt) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[spt++]);
		//spt++;
		//pt--;
	}
}

void size() {
	printf("%d\n", ept-spt);
}
void empty() {
	if (ept ==spt )
		printf("1\n");
	else
		printf("0\n");
}
void front() {
	if (spt == ept)
		printf("-1\n");
	else
		printf("%d\n", arr[spt]);
}
void back() {
	if (spt == ept)
		printf("-1\n");
	else
		printf("%d\n", arr[ept-1]);
}
int main() {
	int N, x;
	spt = 0;
	ept = 0;
	std::string cmd;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		std::cin >> cmd;
		if (cmd.compare("push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		else if (cmd.compare("pop") == 0) pop();
		else if (cmd.compare("size") == 0) size();
		else if (cmd.compare("empty") == 0) empty();
		else if (cmd.compare("front") == 0) front();
		else if (cmd.compare("back") == 0) back();
	}
	return 0;
}
