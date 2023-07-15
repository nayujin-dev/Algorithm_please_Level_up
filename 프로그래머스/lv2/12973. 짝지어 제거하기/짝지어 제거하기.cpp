#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 1;
    vector<char> stack;
    char before=s[0];
    stack.push_back(before);
    
    for(int i=1;i<s.length();i++){
        if(stack.empty()){
            stack.push_back(s[i]);
            continue;
        }
        before=stack.back();
        if(before==s[i]){
            stack.pop_back();
        }else{
            stack.push_back(s[i]);
        }
    }
    
    if(!stack.empty())
        answer=0;
    return answer;
}