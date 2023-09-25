#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i=x,j=0;j<n;i+=x,j++){
        answer.push_back(i);
    }
    return answer;
}