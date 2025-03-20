#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    vector<string> numArr;
    for(int i=0;i<numbers.size();i++){
        numArr.push_back(to_string(numbers[i]));
    }
    sort(numArr.begin(),numArr.end(),compare);
    string answer = "";
    for(int i=0;i<numbers.size();i++){
        answer+=numArr[i];
    }
    if(answer[0]=='0') answer="0";
    return answer;
}