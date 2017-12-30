#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int BiSearch(const vector<int>& nums, int target, int lidx, int ridx);
vector<int> searchRange(vector<int>& nums, int target);

int main(){
    vector<int> nums = {0,0,0,1,2,3};
    vector<int> ans = searchRange(nums, 0);

    cout << ans[0] << "  " << ans[1] << endl;

    return 0;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        if(nums.empty()) return ans;

        int idx = BinarySearch(nums, 0, nums.size()-1, target);
        int l = idx;
        int r = idx;

        while(l>0 && nums[l-1]==nums[l]){
            l--;
        }
        while(r<nums.size()-1 && nums[r+1]==nums[r]){
            r++;
        }

        ans[0] = l;
        ans[1] = r;
        return ans;
    }



int BinarySearch(vector<int>& nums, int lidx, int ridx, int target){
    if(lidx>ridx || nums.empty()){
        return -1;
    }

    int mid = lidx + (ridx-lidx)/2;

    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        if(target>=nums[lidx]){
            return BinarySearch(nums, lidx, mid-1, target);
        }
        else{
            if(nums[mid]>=nums[lidx]){
                return BinarySearch(nums, mid+1, ridx, target);
            }
            else{
                return BinarySearch(nums, lidx, mid-1, target);
            }
        }
    }
    else{
        if(target<nums[lidx]){
            return BinarySearch(nums, mid+1, ridx, target);
        }
        else{
            if(nums[mid]>=nums[lidx]){
                return BinarySearch(nums, mid+1, ridx, target);
            }
            else{
                return BinarySearch(nums, lidx, mid-1, target);
            }
        }
    }

    return -1;
}
