#include <iostream>
#include <vector>

using namespace std;

int main(){


    return 0;
}


int findPeakElement(vector<int>& nums) {
    if(nums.size()<=1) return 0;

    nums.insert(nums.begin(), INT_MIN);
    nums.push_back(INT_MIN);
    int lidx = 1;
    int ridx = nums.size()-2;
    int mid;

    while(lidx <= ridx){
        mid = (ridx+lidx)/2;
        if(nums[mid-1]<=nums[mid] && nums[mid+1]<=nums[mid]){
            return mid-1;
        }
        else if(nums[mid] < nums[mid+1]){
            lidx = mid+1;
        }
        else{
            ridx = mid-1;
        }
    }

    return mid-1;
}


