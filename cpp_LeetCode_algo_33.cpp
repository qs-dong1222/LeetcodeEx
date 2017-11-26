#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    return 0;
}


int search(vector<int>& nums, int target) {
    if(nums[0] > nums[nums.size()-1]){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
        }
    }
    else{
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target) return i;
        }
    }
    return -1;
}
