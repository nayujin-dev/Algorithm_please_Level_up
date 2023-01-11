#include<iostream>
using namespace std;
long long X, Y;
int mid,an;
//게임 1072
int main() {
	scanf("%lld %lld", &X, &Y);
	long long now = (Y * 100) / X;
	if (now >= 99) {
		printf("-1");
		return 0;
	}

	int start = 1;
	int end = 1000000000;
	long long newNum;
	while (start<=end) {
			mid = (start + end) / 2;
		newNum = (Y + mid) * 100 / (X + mid);
		if (newNum > now ) {
			end = mid - 1;
			an = mid;
		}
		else {
			start = mid + 1;
		}
	}
	printf("%d", an);
	//long long newNum = (Y * 100) / X + 1;

	return 0;
}
