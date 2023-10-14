#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int tPt=0, ePt=0, pPt=0;
    while(tPt<=t.size()-p.size()){
        if(pPt==p.size()){
            answer++;
            tPt++;
            ePt=tPt;
            pPt=0;
        }else if(t[ePt]<p[pPt]){
            answer++;
            tPt++;
            ePt=tPt;
            pPt=0;
        }else if(t[ePt]==p[pPt]){
            ePt++;
            pPt++;
        }else{
            tPt++;
            ePt=tPt;
            pPt=0;
        }
    }
   
    return answer;
}