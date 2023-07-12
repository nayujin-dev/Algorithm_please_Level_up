#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fibo[100000+2];
    fibo[1]=1;
    for(int i=2;i<=n;i++){
        if(fibo[i-1]+fibo[i-2]>1234567)
            fibo[i]=fibo[i-1]+fibo[i-2]-1234567;
        else
            fibo[i]=fibo[i-1]+fibo[i-2];
    }
    answer=fibo[n]%1234567;
    return answer;
}