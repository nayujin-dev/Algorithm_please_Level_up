#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),compare);
    // int max=-1;
    for(int i=0;i<citations.size();i++){
        if(i+1<=citations[i]){
            answer=i+1;
        }else{
            break;
        }
        
    }
    return answer;
}