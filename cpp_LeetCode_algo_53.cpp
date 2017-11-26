#include <iostream>
#include <vector>

using namespace std;

int main(){

    return 0;
}

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return 0;

    int ans = INT_MIN;
    int maxV = INT_MIN;

    for(int begin=0; begin<nums.size(); begin++){
        maxV = max(maxV, nums[begin]);
        // 以负数起始的subarray不可能是正确的
        if(nums[begin]<0) continue;
        int sum = 0;
        for(int i=begin; i<nums.size(); i++){
            sum += nums[i];
            // 如果和为负，那还不如直接从后面那个开始，所以和为负就不用继续了
            if(sum < 0){
                begin = i;
                break;
            }
            ans = max(sum, ans);
        }
    }
    if(maxV <=0 ) return maxV;
    return ans;
}
