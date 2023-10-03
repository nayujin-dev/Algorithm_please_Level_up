#include <string>
#include <vector>

using namespace std;

int cnt(int num){
    int tot=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            tot++;
        } 
    }
    return tot;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i=left;i<=right;i++){
        if(cnt(i)%2==0) answer+=i;
        else answer-=i;
    }
    return answer;
}