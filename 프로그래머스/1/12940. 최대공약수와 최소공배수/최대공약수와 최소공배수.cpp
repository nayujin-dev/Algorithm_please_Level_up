#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int num=gcd(n,m);
    
    // 최대공약수 구하기
    answer.push_back(num);
    
    // 최소공배수 구하기
    answer.push_back(n*m/num);
    
    return answer;
}