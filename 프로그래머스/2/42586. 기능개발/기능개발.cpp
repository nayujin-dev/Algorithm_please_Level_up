#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> howlong;
    int day=0;

    for(int i=0;i<progresses.size();i++){
        if((100-progresses[i])%speeds[i]==0)
            day=(100-progresses[i])/speeds[i];
        else
            day= (100-progresses[i])/speeds[i]+1;
        howlong.push_back(day);
    }
    int max=howlong[0];
    int cnt=1;
    for (int i=1;i<howlong.size();i++){
        if(max>=howlong[i]){
            cnt++;
        }else{
            answer.push_back(cnt);
            cnt=1;
            max=howlong[i];
        }
    }
    answer.push_back(cnt);

    return answer;
}