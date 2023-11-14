#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0]<v2[0]) return true;
    else return false;
}
struct cmp2{
    bool operator()(vector<int> v1, vector<int> v2){
        if(v1[1]>v2[1]) return true;
        else return false;   
    }
};
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(),cmp);
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp2> pq;
    int time=0;
    int i=0;
    int tot=0;
    while(i<jobs.size()||!pq.empty()){
        if(i<jobs.size()&& time>=jobs[i][0]){
            pq.push(jobs[i++]);
            continue;
        }
        if(!pq.empty()){
            int start = pq.top()[0];
            int end = pq.top()[1];
            pq.pop();
            time+=end;
            tot+=time-start;
        }else{
            time=jobs[i][0];
        }
    }
    
    return tot/jobs.size();
}