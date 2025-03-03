#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
queue<pair<string,int>> q;
bool visit[50];
string now="";

int bfs( vector<string> words, string target ){ //최소단계 구하기 용 bfs
    while(!q.empty()){
        now=q.front().first;
        int cnt=q.front().second;
        q.pop();   
        for(int i=0;i<words.size();i++){
            // 비교한적 없는 n번째 단어 탐색
            if(visit[i]) continue;    
            // n번째 단어로 비교
            string cmp=words[i];
            int diff=0;
            for(int j=0;j<cmp.size();j++){
                if(diff>=2) break;
                if(now[j]!=cmp[j]) diff++;
            }
            if(diff==1){ // 한글자만 바뀌면 동일한 문자열 존재하는지
                if(cmp.compare(target)==0) // 정답인지
                    return cnt;
                q.push({cmp,cnt+1});
                visit[i]=true;
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    q.push({begin,1});
    answer=bfs(words,target);
    return answer;
}