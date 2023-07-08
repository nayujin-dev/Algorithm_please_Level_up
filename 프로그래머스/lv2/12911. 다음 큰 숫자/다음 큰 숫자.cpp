#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

int countone(int n){
    int onenum=0;
    while(1){
        if(n==0)break;
        if(n%2==1) onenum++;
        n/=2;
    }
    return onenum;
}
int solution(int n) {
    int answer = n+1;
    int num=countone(n);
    while(1){
        if(num==countone(answer++))break;
    }
    answer--;
    
    return answer;
}