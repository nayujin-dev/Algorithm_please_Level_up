#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());
    int max= arr[arr.size()-1];
    int min= arr[0];
    
    for(int i=1;i<arr.size();i++){
        if(arr[i]%min==0){
            min=arr[i];
            cout<<"아직 최소공배수는 "<<min<<endl;
        }else{
            for(int j=arr[i];j<=arr[i]*min;j++){
                if(j%arr[i]==0&&j%min==0){
                    min=j;
                    cout<<"최소공배수는 "<<min<<endl;
                    break;
                }
            }
        }
    }

    answer=min;
    return answer;
}