#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int div=100000000;
    while(n>0){
        if(n/div<10) answer+=n/div;
        n%=div;
        div/=10;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}