#include<cstdio>

int n;
char arr[21];
long long notinf, inf, bm, ibm, div;
int nonPt,rePt;
long long gcd(long long a, long long b) {
	long long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
void trans() {
	nonPt = 2;
	rePt = 0;
	notinf = inf = 0;
	bm = 10;
	ibm = 0;
	while (1) { //비순환구조 까지
		if (arr[nonPt] == '(')
		{
			rePt = nonPt + 1; //rePt=순환소수의 첫번째자리 인덱스
			nonPt--; //nonPt=비순환소수의 마지막자리 인덱스
			break;
		}
		else if (arr[nonPt] == NULL) {
			nonPt--;
			break;
		}
		nonPt++;
	}

	//비순환소수 값 구하기
	for (int j = 2; j <= nonPt; j++) { 
		notinf += (arr[j] - '0');
		inf += (arr[j]-'0');
		bm *= 10; //비순환소수 자리만큼 10곱함
		notinf *= 10;
		inf *= 10;
	}
	
	//순환소수 값 구하기
	for (int j = rePt;; j++) {
		if (arr[j] == ')'||j==0) {
			ibm /= 10;
			inf /= 10;
			break;
		}
		inf += (arr[j]-'0');
		inf *= 10;
		ibm += 9;
		ibm *= 10;
	}

	//순환구간 없을떄
	if (ibm == 0) {
		notinf /= 10;
		bm /= 10;
		div = gcd(bm,notinf);
		printf("%lld/%lld\n", notinf / div, bm / div);
	}
	else if (nonPt<=1) {//비순환 구간 없을때
		div = gcd(ibm, inf);
		printf("%lld/%lld\n", inf / div, ibm / div);
	}
	else { //둘다 있을때
		notinf /= 10;
		bm /= 10;
		ibm *= bm;

		inf -= notinf;
		div = gcd(ibm, inf);
		printf("%lld/%lld\n", inf / div, ibm / div);
	}
	return;
}
int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &arr);
		trans();
	}
	return 0;
}