#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i=0;i<completion.size();i++){
        if(participant[i].compare(completion[i])){
            return participant[i];
        }
    }
    // return answer;
    int size=participant.size()-1;
    return participant[size];
}