#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string toBinary(int x){
    string r;
    while(x!=0){
        r+= (x%2==0?"0":"1");
        x/=2;
    }
    return r;
}
vector<int> solution(string s) {
    vector<int> answer;
    int count=0, num=0;
    
    while(s.compare("1")){
        int i=0;
        int numone=0;
        for(;i<s.size();i++){
            if(s[i]=='1')
                numone++;
        }
        s=toBinary(numone);
        count++;
        num+=i-numone;
        // std::cout<<s<<endl;
    }
    answer.push_back(count);
    answer.push_back(num);
    return answer;
}