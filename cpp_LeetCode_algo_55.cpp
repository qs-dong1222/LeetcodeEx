#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums);

int main(){
    vector<int> nums = {3,2,1,0,4};

    canJump(nums);

    return 0;
}


/*
类似之前的 范围前进 概念， 如果当前范围可以找到下一个更远的范围，就代表有前进的可能性。
反之，如果当前范围找不到更远的范围，就说明当前范围只能在当前范围里跑，就卡在当前范围了。
那也就不能跳到最后，那么就是失败。反之，一直前进就有可能成功。
*/
bool canJump(vector<int>& nums) {
    if(nums.empty()) return false;

    int startIdx = 0;
    int endIdx = 0;
    int tempIdx;
    int maxEnd = endIdx;
    while(endIdx < nums.size()-1){
        for(tempIdx = startIdx; tempIdx<=endIdx; tempIdx++){
            //找下一个range的最远endIdx
            maxEnd = max(maxEnd, nums[tempIdx]+tempIdx);
            //如果下一个范围能跑的超过lastidx，说明能跑到最后
            if(maxEnd >= nums.size()-1) return true;
        }

        startIdx = endIdx+1;
        //如果当前范围找到的下一个endidx还在当前范围内，说明就卡在当前范围了，不能成功
        if(maxEnd <= endIdx) return false;
        endIdx = maxEnd;
    }
    //只有当endIdx跑到最后了，才有可能跳出循环，那就说明能成功
    return true;
}
