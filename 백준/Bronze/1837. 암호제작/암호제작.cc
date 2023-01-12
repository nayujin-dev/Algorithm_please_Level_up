
#include<iostream>
#include <string>
#define MAX (1000000+3)
#define INF (1000000000)

using namespace std;

bool isNotPrimenumber[MAX];
string inputStr;
int K;
int an;
void makePrimenumber() {
	// 0-1. 에라토스테네스의 체
	for (int i = 2; i * i < MAX; i++)
	{
		if (isNotPrimenumber[i] == false) {
			for (int j = i * i; j < MAX; j += i)
			{
				isNotPrimenumber[j] = true;
			}
		}
	}
}

int main() {

	makePrimenumber();
	std::cin >> inputStr;
	scanf("%d",&K);

	int tmp;
	an = INF;
	for (int i = 2; i < K;i++) {
		tmp = 0;
		if (isNotPrimenumber[i]) {
			continue;
		}
		for (int j = 0; j <inputStr.size() ; j++)
			tmp = (tmp * 10 + inputStr[j] - '0') % i;
		if (tmp == 0) {
			an = i;
			break;

		}
	
	}
	if (an < K)
		printf("BAD %d", an);
	else
		printf("GOOD");
	return 0;
	

}