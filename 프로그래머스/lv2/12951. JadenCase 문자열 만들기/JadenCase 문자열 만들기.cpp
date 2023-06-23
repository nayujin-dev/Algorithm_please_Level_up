#include <string>
#include <vector>
// #include <cctype>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string strBf;
    for(int i=0;i<s.size();i++){
        if(i==0 || s[i-1]==' '){
            if(s[i]>='a'&&s[i]<='z')
                answer+=s[i]-32;
            else
                answer+=s[i];
        }else{
            if(s[i]>='A'&&s[i]<='Z')
                answer+=s[i]+32;
            else
                answer+=s[i];
        }
            
    }
//     while(getline(ss,strBf,'')){
//         if(strBf[0]>='a'&&strBf[0]<='z'){
//             answer+=strBf[0]-=32;
//             for(int i=1;i<strBf.size();i++){
//                 if(strBf[i]>='A'&&strBf[i]<='Z')
//                     answer+=strBf[i]+=32;
//                 else
//                     answer+=strBf[i];
//             }
//         }else if(){
            
//         }else{
//             answer+=strBf;            
//         }
//         answer+=" ";
//     }

    // for(int i=0;i<answer.size();i++){
    //     cout<<answer[i];
    // }
    // answer.pop_back();
    return answer;
}