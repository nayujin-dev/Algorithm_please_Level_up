#include <iostream>

using namespace std;

int count(int n){
    int num=1;
    while(1){
        n/=2;
        if(n==1)
            return num;
        num++;
    }
}
int solution(int n, int a, int b)
{
    int answer = 1;
    int m=count(n);
    for(int i=0;i<m;i++){
        if(abs(a-b)==1 && a/2!=b/2) break;
        a%2==0?a/=2:a=(a+1)/2;
        b%2==0?b/=2:b=(b+1)/2;
        answer++;
        // cout<<i+1<<"번째, "<<a<<" "<<b<<", num: "<<answer<<endl;

    }

    return answer;
}