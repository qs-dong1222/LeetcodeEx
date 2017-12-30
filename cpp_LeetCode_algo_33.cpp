#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int search(vector<int>& nums, int target);
int BinarySearch(vector<int>& nums, int lidx, int ridx, int target);

int main(){

    vector<int> nums =
    //{4,5,6,7,0,1,2};
    //{4,5,6,7,7,7,-3,-2,0,1,2};
    {5,1,3};

    cout << search(nums, 5) << endl;

    return 0;
}


/*
solution : o(n)
*/
//int search(vector<int>& nums, int target) {
//    if(nums.empty()) return -1;
//    if(nums[0] > nums[nums.size()-1]){
//        for(int i=0;i<nums.size();i++){
//            if(nums[i]==target) return i;
//        }
//    }
//    else{
//        for(int i=nums.size()-1;i>=0;i--){
//            if(nums[i]==target) return i;
//        }
//    }
//    return -1;
//}





/*
solution : binary search
*/
int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;

    return BinarySearch(nums, 0, nums.size()-1, target);
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
