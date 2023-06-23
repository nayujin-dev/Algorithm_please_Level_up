#include <string>
#include <vector>
// #include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int garo,i=1;
    garo=(brown-4)/2;
    for(;i<=garo/2;i++){
        if(i*(garo-i)==yellow){
            break;
        }
    }
    // cout<<"가로: "<<garo-i+2<<" 세로: "<<i+2<<endl;
    
    vector<int> answer;
    
    answer.push_back(garo-i+2);
    answer.push_back(i+2);
    return answer;
}