#include<iostream>

using namespace std;
int gcd(int a, int b) { //b<a 여야함. a를 b로 나눌거라
	if (b > a) {
		int tmp = b;
		b = a;
		a = tmp;
	}
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	// 인풋 받기
	int a, b, c, d,newx,newy,div;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	// 만약 분모 같다면?
		//그냥 분자끼리 더함
	if (b == d) {
		newy = b;
	}
	else {
		a = a * d;
		c = c * b;
		newy = b * d;
	}
	newx = a + c;
	div = gcd(newx, newy);

	newx = newx / div;
	newy = newy / div;

	printf("%d %d", newx, newy);
	// 분모 서로 다르다면?
		//통분 후 더함
	// 새로 생긴 분자 분모에 대해 유클리드호제법
	return 0;
}