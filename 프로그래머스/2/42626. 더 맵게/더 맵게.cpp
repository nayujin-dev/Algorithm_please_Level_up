#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>,greater<int>> pq;
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.size()>=2){
        if(pq.top()<K){
            answer++;
            int x= pq.top();
            pq.pop();
            int y= pq.top();
            pq.pop();
            pq.push(x+2*y);
        }else break;
    }
    if(pq.top()<K) answer = -1;
    return answer;
}