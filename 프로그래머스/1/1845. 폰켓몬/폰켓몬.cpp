#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> cnt;
    for(int i=0;i<nums.size();i++){
        int idx=nums[i];
        cnt.insert(idx);
    }
    int answer = 0;
    if(nums.size()/2<=cnt.size()){
        answer = nums.size()/2;
    }else{
        answer=cnt.size();
    }
    return answer;
}