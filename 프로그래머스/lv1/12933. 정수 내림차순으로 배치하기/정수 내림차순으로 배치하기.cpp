#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> newArr;
    string arr=to_string(n);
    for(int i=0;i<arr.size();i++){
        newArr.push_back(arr[i]-'0');
    }
    sort(newArr.begin(), newArr.end(),greater<>());

    for(int i=0;i<arr.size();i++){
        answer+=newArr[i];
        answer*=10;
    }
    return answer/=10;
}