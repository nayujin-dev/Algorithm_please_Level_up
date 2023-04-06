#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string arr[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    string answer = "";
    switch(a){
        case 1:
            answer=arr[(b-1)%7];
            break;
        case 2:
            answer=arr[(2+b)%7];
            break;
        case 3:
            answer=arr[(b+3)%7];
            break;
        case 4:
            answer=arr[(b+6)%7];
            break; 
        case 5:
            answer=arr[(b+1)%7];
            break;
        case 6:
            answer=arr[(b+4)%7];
            break;
        case 7:
            answer=arr[(b+6)%7];
            break;
        case 8:
            answer=arr[(b+2)%7];
            break;
        case 9:
            answer=arr[(b+5)%7];
            break;
        case 10:
            answer=arr[(b)%7];
            break;
        case 11:
            answer=arr[(b+3)%7];
            break;
        case 12:
            answer=arr[(b+5)%7];
            break;
    }
    return answer;
}