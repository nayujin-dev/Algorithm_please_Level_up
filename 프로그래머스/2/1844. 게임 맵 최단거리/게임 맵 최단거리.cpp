#include<vector>
#include<queue>
using namespace std;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int n,m;
int answer=10000;
bool visit[100][100];
int dist[100][100];

queue<pair<int,int>> q;

void bfs(vector<vector<int> > maps){
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx>=0 && ny >=0 && nx<m && ny<n){
                if(!visit[nx][ny]&&maps[nx][ny]==1){
                    visit[nx][ny]=true;
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }

        }
    }
   
    return;
   
}

int solution(vector<vector<int> > maps)
{
    n=maps[0].size();
    m=maps.size();
    
    visit[0][0]=true;
    dist[0][0]=1;
    q.push({0,0});
    bfs(maps);
    if(!dist[m-1][n-1])
        answer=-1;
    else
        answer=dist[m-1][n-1];
    return answer;
}

