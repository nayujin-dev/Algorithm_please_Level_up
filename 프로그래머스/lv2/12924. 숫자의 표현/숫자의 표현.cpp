#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0, nowPt=1, start=1, sum=0;
    while(1){
        if(sum==n) {
            // cout<<now<<"부터 "<<pt-1<<endl;
            answer++;
            sum=0;
            nowPt=++start;
        }else if(start>n)
            break;
        else if(sum>n){
            nowPt=++start;
            sum=0;
        }
        sum+=nowPt++;
    }
    return answer;
}