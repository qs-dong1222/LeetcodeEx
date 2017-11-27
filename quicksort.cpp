#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;
void QuickSort(vector<int>& nums, int lidx, int ridx);

int main(){
                    //  0,1,2,3,4,5,6
    vector<int> nums = //{1,0,2};
    {3,5,0,-2,1,6,0,4,8,0,7,4,4};
    QuickSort(nums, 0, nums.size()-1);

    for(auto each : nums){
        cout << each << " ";
    }

    return 0;
}


void QuickSort(vector<int>& nums, int lidx, int ridx){
    if(lidx>=ridx) return;

    int subject = nums[ridx];
    int r = ridx-1;
    while(lidx < r){
        // if left number is < subject, we continue finding until the first number >= subject
        // the reason we dont have '<=' is that if a number is the same as subject, then this number
        // should be put on the right side of subject. the left side is always less than subject
        while(nums[lidx] < subject)
            lidx++;

        while(nums[r] >= subject)
            r--;

        if(r > lidx)
            swap(nums[lidx], nums[r]);
    }

    if(nums[lidx] > subject){
        swap(nums[lidx], nums[ridx]);
    }

    QuickSort(nums, 0, lidx-1);
    QuickSort(nums, lidx+1, ridx);
}

