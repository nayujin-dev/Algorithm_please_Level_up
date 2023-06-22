#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string solution(string s) {
    istringstream ss(s);
    string strBf;
    vector<string> num;
    int size=0;
    int minA,maxA;
    
    // int minA=1000,maxA=0;

    while(getline(ss,strBf,' ')){
        num.push_back(strBf);
        cout<<strBf<<' ';
        size++;
    }
    for(int i=0;i<size;i++){
        if(i==0){
                minA=maxA=stoi(num[i]);
        }else{
            maxA=max(stoi(num[i]),maxA);
            minA=min(stoi(num[i]),minA);
        }
        
        cout<<"최대 " <<maxA <<" 최소 "<<minA<<endl;
    }
    string answer = "";
    answer+=to_string(minA);
    answer+=" ";
    answer+=to_string(maxA);
    return answer;
}