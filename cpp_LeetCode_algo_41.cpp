#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int firstMissingPositive(vector<int>& nums);

int main(){
    vector<int> nums =
    //{-1,4,2,1,9,10};
    //{0,1,2};

    cout << firstMissingPositive(nums) << endl;

    return 0;
}





int firstMissingPositive(vector<int>& nums) {
    if(nums.empty()) return 1;
    int i;
    for(i=0;i<nums.size();i++){
        // 这个地方 必须要是 while，以防止 “换过去的数对，换回来的数不对” 的情况
        while(nums[i]>0 && nums[nums[i]-1]!=nums[i] && nums[i]<nums.size()){
            swap(nums[nums[i]-1], nums[i]);
        }
    }

    for(i=0;i<nums.size();i++){
        if(nums[i] != i+1 && nums[i]>=0)
            return i+1;
        if(nums[i] <=0)
            return i+1;
    }

    return i;
}
