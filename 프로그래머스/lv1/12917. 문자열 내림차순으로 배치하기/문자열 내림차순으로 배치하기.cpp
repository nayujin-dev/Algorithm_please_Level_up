#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size()-i;j++){
            if(s[j]<s[j+1]){
                char a=s[j+1];
                s[j+1]=s[j];
                s[j]=a;
            }
        }
    }
    return s;
}