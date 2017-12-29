#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int helper(vector<int>& nums, int lidx, int ridx, int k);
void printArr(vector<int>& nums);

int main(){
    vector<int> nums = {3,1,2,4};
    cout << helper(nums, 0, nums.size()-1, 2) << endl;
    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    return helper(nums, 0, nums.size()-1, k);
}


int helper(vector<int>& nums, int lidx, int ridx, int k){
    swap(nums[lidx+rand()%(ridx-lidx+1)], nums[ridx]);
    int pivot = nums[ridx];

    int l = lidx;
    int r = ridx-1;

    while(l <= r){
        while(l <= r && nums[r]>=pivot){
            r--;
        }

        while(l <= r && nums[l]<pivot){
            l++;
        }

        if(l <= r){
            swap(nums[r], nums[l]);
            l++;
            r--;
        }
    }
    swap(nums[l], nums[ridx]);

    if(ridx-l+1 == k){
        return nums[l];
    }
    else if(ridx-l+1 < k){
        return helper(nums, lidx, l-1, k-(ridx-l+1));
    }
    else{
        return helper(nums, l+1, ridx, k);
    }
}





void printArr(vector<int>& nums){
    for(auto each : nums){
        cout << each << " ";
    }
    cout << endl;
}

