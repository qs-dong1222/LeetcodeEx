#include <iostream>
#include <vector>

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
    while(lidx < ridx){
        mid = (lidx+ridx)>>1;

        if(nums[mid] > nums[ridx]){
            lidx = mid+1;
        }
        else if(nums[mid] < nums[ridx]){
            ridx = mid;
        }
        else{
            // nums[mid] == nums[ridx] there may be a case like [3,3,3,1,3]
            // min is at valley, ridx cannot jump to mid directly, you may miss the min.
            // you need to move to left step by step.
            ridx--;
        }
    }

    return nums[ridx];
}

