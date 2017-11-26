#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void nextPermutation(vector<int>& nums);
int main(){
    vector<int> nums = {5,4,3,2,1};

    nextPermutation(nums);

    for(auto each:nums){
        cout << each << " ";
    }

    return 0;
}



void nextPermutation(vector<int>& nums) {
    if(nums.empty()) return;
    int revIdx = nums.size()-1;
    int lidx, ridx = nums.size()-1;
    while(nums[revIdx-1] >=  nums[revIdx] && revIdx>0)
        revIdx--;
    if(revIdx == 0){
        sort(nums.begin(), nums.end());
    }
    else{
        lidx = revIdx-1;
        while(nums[ridx] <= nums[lidx]) ridx--;
        swap(nums[lidx], nums[ridx]);
        sort(nums.begin()+lidx+1, nums.end());
    }
}
