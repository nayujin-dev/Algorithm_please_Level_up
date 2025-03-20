#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// bool compare(int a, int b){
//     return a>b;
// }

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max=-1;
    queue<pair<int,int>> q;
    priority_queue<int,vector<int>> maxNum;
    for(int i=0;i<priorities.size();i++){
        // if(max<priorities[i]){
        //     max=priorities[i];
        // }
        q.push({priorities[i],i});
        maxNum.push(priorities[i]);
    }
    // sort(maxNum.begin(),maxNum.end(),compare);
    int priority=1;
    max=maxNum.top();
    maxNum.pop();
    while(!q.empty()){
        int cmpValue = q.front().first;
        int cmpIdx = q.front().second;
        q.pop();
        if(cmpValue<max){
            q.push({cmpValue,cmpIdx});
        }else{
            priorities[cmpIdx]=priority;
            priority++;
            max=maxNum.top();
            maxNum.pop();
        }
    }
    return priorities[location];
}