#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int i, int tot, vector<int> numbers, int target){
    if (i==numbers.size()){
        if(tot==target) answer++;
        return ;
        
    }
    dfs(i+1, tot+numbers[i],numbers, target);
    dfs(i+1, tot-numbers[i],numbers, target);
} 

int solution(vector<int> numbers, int target) {
    dfs(0,0, numbers,target); 
    return answer;
}
