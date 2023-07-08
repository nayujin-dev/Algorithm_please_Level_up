#include <bitset>

using namespace std;

int solution(int n) {
    int num=bitset<20>(n).count();
    int answer=n+1;
    int one=bitset<20>(answer).count();
    while(num!=one){
        one=bitset<20>(++answer).count();
    }
    return answer;
}