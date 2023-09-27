#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int mul=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='-'){
            return answer*=(-1);
        }else if(s[i]=='+'){
            return answer;
        }else{
            answer=answer+mul*(s[i]-'0');
            mul*=10;
        }
    }
    return answer;
}