#include <string>
#include <vector>
#include <string>
using namespace std;

bool solution(int x) {
    string arr=to_string(x);
    int div=0;
    for(int i=0;i<arr.size();i++){
        int a=arr[i]-'0';
        div+=a;
    }
    if(x%div==0) return true;
    else return false;
}