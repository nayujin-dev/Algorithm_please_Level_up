#include <iostream>
#include <string>
#define NUM (1000000000)
#define ABS(a) ((a)>0? (a) : (-a))

using namespace std; 

void numX(int x);
void pop();
void inv();
void dup();
void swp();
void add();
void sub();
void mul();
void div();
void mod();

void input();
void program();

int flag;
int x, N;
char inputStr[5];

int cmd[100001]; // 명령어 개수
int num[100001];
int inNum[10001];

// 고스택 자료구조
long long stack[1002];
int cPt, nPt, pt;



int main() {

	//freopen("input.txt", "r", stdin);
	
	// 탈출조건 나올때까지 무한 반복
	while(1){
		// 1. 입력
		input();
		// ** QUIT 나오면 프로그램 종료
		if (flag == -1) return 0;
		// 2. 구현부
		program();
	}
	return 0;
}

void input() {
	flag = cPt = nPt = 0;

	while(1) {
		scanf("%s", &inputStr[0]);

		// flag 값 설정
		// NUM 0 / POP 1 / INV 2 / DUP 3 / DIV 4 / SWP 5 / SUB 6 / ADD 7
		// MUL 8 / MOD 9 / END break / QUIT -1 / ERROR -2

		if (inputStr[0] == 'N') {
			scanf("%d", &x);
			cmd[cPt++] = 0;
			num[nPt++] = x;
		}
		else if (inputStr[0] == 'P') cmd[cPt++] = 1;
		else if (inputStr[0] == 'I') cmd[cPt++] = 2;
		else if (inputStr[0] == 'D') {
			if (inputStr[1] == 'U') cmd[cPt++] = 3;
			else cmd[cPt++] = 4;
		}
		else if (inputStr[0] == 'S') {
			if (inputStr[1] == 'W') cmd[cPt++] = 5;
			else cmd[cPt++] = 6;
		}
		else if (inputStr[0] == 'A') cmd[cPt++] = 7;
		else if (inputStr[0] == 'M') {
			if (inputStr[1] == 'U') cmd[cPt++] = 8;
			else cmd[cPt++] = 9;
		}
		else if (inputStr[0] == 'E') break;
		else if (inputStr[0] == 'Q') {
			flag = -1;
			return;
		}
	}

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &inNum[i]);
	}

}

void program() {
	for (int i = 1; i <= N; i++) {
		nPt = pt = 0;
		stack[pt++] = inNum[i];
		for (int j = 0; j < cPt; j++) {
			flag = cmd[j];

			// flag 값 설정
			// NUM 0 / POP 1 / INV 2 / DUP 3 / DIV 4 / SWP 5 / SUB 6 / ADD 7
			// MUL 8 / MOD 9 / END break / QUIT -1 / ERROR -2

			if (flag == 0) {	// NUM
				numX(num[nPt++]);
			}
			else if (flag == 2) {	// INV
				inv();
			}
			else if (pt == 0) {
				flag = -2;
				break;
			}
			else if (flag == 1) {	// POP
				pop();
			}
			else if (flag == 3) {	// DUP
				dup();
			}
			else if (pt == 1) {
				flag = -2;
				break;
			}
			else if (flag == 4) {	// DIV
				div();
			}
			else if (flag == 5) {	// SWP
				swp();
			}
			else if (flag == 6) {	// SUB
				sub();
			}
			else if (flag == 7) {	// ADD
				add();
			}
			else if (flag == 8) {	// MUL
				mul();
			}
			else if (flag == 9) {	// MOD
				mod();
			}
			if (flag == -2) break;
		}
		if (flag == -2 || pt != 1) printf("ERROR\n");

		else printf("%lld\n", stack[0]);
	}
	printf("\n");
}

void numX(int x) {
	stack[pt++] = x;
}

void pop() {
	pt--;
}

void inv() {
	stack[pt - 1] = -stack[pt - 1];
}

void dup() {
	stack[pt++] = stack[pt - 1];
}

void swp() {
	long long tmp = stack[pt - 1];
	stack[pt - 1] = stack[pt - 2];
	stack[pt - 2] = tmp;
}

void add() {
	long long tmp = stack[pt - 1] + stack[pt - 2];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[pt - 2] = tmp;
	pt--;
}

void sub() {
	long long tmp = stack[pt - 2] - stack[pt - 1];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[pt - 2] = tmp;
	pt--;
}

void mul() {
	long long tmp = stack[pt - 2] * stack[pt - 1];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[pt - 2] = tmp;
	pt--;
}

void div() {
	long long tmp1, tmp2;
	int tFlag = 0;
	if (stack[pt - 1] == 0) {
		flag = -2;
		return;
	}
	tmp1 = stack[pt - 2];
	tmp2 = stack[pt - 1];
	if (tmp1 < 0) tFlag++;
	if (tmp2 < 0) tFlag++;
	tmp1 = ABS(tmp1) / ABS(tmp2);
	if (tFlag == 1) stack[pt - 2] = -tmp1;
	else stack[pt - 2] = tmp1;
	pt--;
}

void mod() {
	long long tmp;
	if (stack[pt - 1] == 0) {
		flag = -2;
		return;
	}
	tmp = ABS(stack[pt - 2]) % ABS(stack[pt - 1]);
	if (stack[pt - 2] < 0) stack[pt - 2] = -tmp;
	else stack[pt - 2] = tmp;
	pt--;
}