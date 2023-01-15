#include<cstdio>
char arr[31];
char arrS[31];
char arrE[31];
int num[31];
int an = 0;
int spt = 0;
int npt = 0;
int calnum = 1;
int i = 0;

bool isWrong;
void cal(int pt) {

	if (arr[pt] == '(') {
		arrS[spt++]='(';
		calnum *= 2;
	}
	else if (arr[pt] == '[') {
		arrS[spt++]='[';
		calnum *= 3;
	}
	else if (arr[pt] == ')') {
		if (arr[pt-1] == '(') {
			an += calnum;
			calnum /= 2;
			spt--;
		}
		else if(arrS[spt-1] != '('||spt<0){
			an = 0;
			isWrong = true;
		}
		else {
			calnum /= 2;
			spt--;
		}
	}
	else if (arr[pt] == ']') {
		if (arr[pt - 1] == '[') {
			an += calnum;
			calnum /= 3;
			spt--;
		}
		else if (arrS[spt - 1] != '[' || spt < 0) {
			an = 0;
			isWrong = true;
		}
		else {
			calnum /= 3;
			spt--;
		}
	}

	return;
}
int main() {
	scanf("%s", &arr);
	while (1) {
		if (arr[i] == 0)
			break;
		else {
			if (isWrong) {
				printf("0");
				return 0;
			}
			cal(i++);

			//printf("현재 arrS: ");
			//for(int i=0;i<=spt;i++)
			//	printf("%c", arrS[i]);
			//printf("\n");
		}
	}
	if (spt == 0) {
		printf("%d", an);

	}
	else {
		printf("0");
	}
	return 0;
}