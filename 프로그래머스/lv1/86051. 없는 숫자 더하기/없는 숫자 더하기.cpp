#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 9*10/2;
    for(int i=0;i<numbers.size();i++){
        answer-=numbers[i];
    }
    return answer;
}