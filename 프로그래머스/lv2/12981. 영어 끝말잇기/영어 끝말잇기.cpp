#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string before = words[0];
    
    for(int i=1;i<words.size();i++){
        if(words[i][0]!=before[before.length()-1]){
            // cout<<words[i][0]<<" "<<before[before.length()-1]<<endl;
            answer.push_back((i+1)%n==0?+n:(i+1)%n);
            answer.push_back(i/n+1);
            return answer;
        }else{
            for(int j=0;j<i;j++){
                if(!words[j].compare(words[i])){
                    // cout<<"i "<<i<<" "<<words[i]<<endl;
                    answer.push_back((i+1)%n==0?n:(i+1)%n);
                    answer.push_back(i/n+1);
                    return answer;
                }
            }
        }
        before=words[i];
    }
    if(answer.empty()){
        answer.assign(2, 0);
    }

    return answer;
}