#include<iostream>
#include<algorithm>

using namespace std;
char inputStr[100001];
bool compare(int i, int j) {
	return j < i;
}
int main() {
	int sum = 0;
	//1. n 인풋받기
	scanf("%s", inputStr);

	// 2. 문자열 정렬
	int len;
	for (len = 0; inputStr[len] != 0; len++);
	sort(inputStr, inputStr + len, compare);
	
	// if 받은거 중에 0 없으면 -1 출력
	if (inputStr[len-1] != '0') {
		printf("-1");
		return 0;
	}
	for(int i=0;i<len;i++){
		sum += inputStr[i]+'0';
	}
    // else 나머지 수의 합이 3의 배수
	if (sum % 3 == 0) {
		printf("%s", inputStr);
	}else
		printf("-1");
	return 0;



}