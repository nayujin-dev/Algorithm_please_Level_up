#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visit[10000+2];
vector<string> answer;
bool isDone;

void dfs(string start,vector<vector<string>> tickets, int cnt){
    
    if(tickets.size()==cnt) {
        cout<< "카운트:"<<cnt;
        isDone=true;
        return;
    };
    for(int i=0;i<tickets.size();i++){
        if(!visit[i] && tickets[i][0].compare(start)==0) {
            string dest=tickets[i][1];
            answer.push_back(dest);
            visit[i]=true;
            cout<< dest<<", "<<cnt<<" ";
            dfs(dest, tickets,cnt+1);
            if(!isDone){
                visit[i]=false;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    // 알파벳 순으로 dfs 작동하도록 sort
    sort(tickets.begin(),tickets.end());
    
    answer.push_back("ICN");
    dfs("ICN", tickets,0);
    
    // for(int i=0;i<tickets.size();i++){
    //     if(tickets[i][0].compare("ICN")==0) {
    //         dest=tickets[i][1];
    //         visit[i]=true;
    //         answer.push_back("ICN");
    //         answer.push_back(dest);
    //         cnt.push_back(true);
    //     }
    // }
   

    return answer;
}