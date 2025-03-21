#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
bool checked[9999999+1];
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    
    do{
        string str="";
        for(int i=0;i<numbers.size();i++){
            str+=numbers[i];
            int num=stoi(str);
            if(!checked[num]&&isPrime(num)){
                answer++;
                checked[num]=true;
            }
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    return answer;
}