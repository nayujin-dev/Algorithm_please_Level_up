#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    char arr[100000+1];
    int p=0;
    bool answer = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            arr[p++]='(';
        }else if(s[i]==')'){
            if(p>0&&arr[p-1]=='(') p--;
            else{
                answer=false;
                break;
            }
                
        }else{
            answer=false;
            break;            
        }
    }
    if(p!=0)
        answer=false;
    return answer;
}