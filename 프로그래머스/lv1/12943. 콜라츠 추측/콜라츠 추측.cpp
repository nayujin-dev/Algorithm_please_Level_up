#include <string>
#include <vector>
using namespace std;

long long collatz(long long n){
    if(n%2==0){
        return n/2;
    }else{
        return n*3+1;
    }
}

int solution(int num) {
    int answer = 0;
    long long newNum=num;
    if(num==1) return answer;
    for(int i=1;i<=500;i++){
        if(newNum==1){
            return answer;
        }
        newNum=collatz(newNum);
        answer++;
    }
    return -1;
}

