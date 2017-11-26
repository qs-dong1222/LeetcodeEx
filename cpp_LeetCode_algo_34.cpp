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
    if(nums.empty()) return vector<int>(2,-1);
    int res = BiSearch(nums, target, 0, nums.size()-1);
    if(res == -1) return vector<int>(2,-1);

    int lidx = res;
    int ridx = res;
    while( !(nums[lidx-1]!=target && nums[ridx+1]!=target) ){
        if(nums[lidx-1]==target) lidx--;
        if(nums[ridx+1]==target) ridx++;
    }

    vector<int> ans;
    ans.push_back(lidx);
    ans.push_back(ridx);
    return ans;
}

int BiSearch(const vector<int>& nums, int target, int lidx, int ridx){
    if(lidx > ridx){
        return -1;
    }

    int mid = lidx+(ridx-lidx)/2;
    if(target==nums[mid]) return mid;
    if(target > nums[mid]){
        return BiSearch(nums, target, mid+1, ridx);
    }
    else if(target < nums[mid]){
        return BiSearch(nums, target, 0, mid-1);
    }
}
