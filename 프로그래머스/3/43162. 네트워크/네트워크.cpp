#include <string>
#include <vector>
#include <queue>
using namespace std;
int answer = 0;
bool visit[200];
queue<int> q;

void bfs(int where, vector<vector<int>> computers){
    visit[where]=true;
    q.push(where);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<computers.size();i++){
            if(!visit[i] && computers[x][i]==1 && x!=i){
                visit[i]=true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<computers.size();i++){
        if(!visit[i]){
            bfs(i, computers);
            answer++;        
        }
    }
    return answer;
}