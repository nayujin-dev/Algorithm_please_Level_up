#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int i, int j){
    return j<i; 
}
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(), compare);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;
    for(int i=0;i<A.size();i++){
        answer+=A[i]*B[i];
    }

    return answer;
}