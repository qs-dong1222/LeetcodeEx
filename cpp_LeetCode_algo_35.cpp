#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);
int BinarySearch(vector<int>& nums, int lidx, int ridx, int target);

int main(){

    vector<int> nums =
    {1,3,3,3,5,6,7};

    cout << searchInsert(nums, 2) << endl;


    return 0;
}



int searchInsert(vector<int>& nums, int target) {
    return BinarySearch(nums, 0, nums.size()-1, target);
}


int BinarySearch(vector<int>& nums, int lidx, int ridx, int target){
    if(lidx > ridx){
        return lidx;
    }

    int mid = lidx + (ridx-lidx)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        return BinarySearch(nums, lidx, ridx-1, target);
    }
    else{
        return BinarySearch(nums, mid+1, ridx, target);
    }
}
