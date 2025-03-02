#include <vector>
#include <iostream>

using namespace std;
bool exist[10];
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int x = arr[0];
    answer.push_back(x);
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=x){
            answer.push_back(arr[i]);
            x=arr[i];
        }
    }
   
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}