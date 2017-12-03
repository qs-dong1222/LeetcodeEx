#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int findMin(vector<int>& nums);

int main(){
    vector<int> nums = {2,1};
    //{1};
    //{1,2,3,4,5,6,7,8,9,10,11,12};
    //{5,6,7,8,9,9,9,10,11,0,1,2,3,3,3,4};

    cout << findMin(nums) << endl;

    return 0;
}


int findMin(vector<int>& nums){
    if(nums.empty()) return 0;

    int lidx = 0;
    int ridx = nums.size()-1;
    int mid;
    // can not be lidx = ridx, if we found min and ridx @ min, lidx also @ min, we will stuck in loop.
    while(lidx < ridx){
        mid = (lidx+ridx)>>1;

        if(nums[mid]>nums[ridx]){
            lidx = mid+1;
        }
        else{
            // cant not be mid-1. if we already at the min, ridx = mid-1 will skip the
            // real min in next around.
            ridx = mid;
        }
    }

    return nums[ridx];
}
