#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = fourSum(nums, 0);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}







vector<vector<int>> fourSum(vector<int>& nums, int target){
    vector<vector<int>> ans;
    if(nums.empty() || nums.size()<4) return ans;

    sort(nums.begin(), nums.end());

    for(int i=0;i<(int)nums.size()-3;i++){
        for(int j=i+1;j<(int)nums.size()-2;j++){
            int l = j+1;
            int r = nums.size()-1;

            while(l < r){
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    vector<int> curr = {nums[i], nums[j], nums[l], nums[r]};
                    ans.push_back(curr);
                    // skip repetitive nums
                    while(l<r && nums[l+1]==nums[l]) l++;
                    while(l<r && nums[r-1]==nums[r]) r--;
                    l++;
                    r--;
                }
            }
            while(j<(int)(nums.size()-2) && nums[j+1]==nums[j]) j++; // skip repetitive nums
        }
        while(i<(int)(nums.size()-3) && nums[i+1]==nums[i]) i++; // skip repetitive nums
    }

    return ans;
}

















//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//    vector<vector<int>> ans;
//    if(nums.empty()){
//        return ans;
//    }
//
//    sort(nums.begin(), nums.end());
//
//    vector<int> tmp;
//    int target_2sum;
//    int lidx, ridx;
//
//    for(int i=0; i<nums.size()-3; i++){
//        for(int j=i+1; j<nums.size()-2; j++){
//            target_2sum = target - nums[i] - nums[j];
//            lidx = j+1;
//            ridx = nums.size()-1;
//
//            while(lidx < ridx){
//                if(nums[lidx] + nums[ridx] == target_2sum){
//                    tmp = {nums[i], nums[j], nums[lidx], nums[ridx]};
//                    ans.push_back(tmp);
//                    lidx++;
//                    while(lidx < ridx && nums[lidx] == nums[lidx-1]) lidx++;
//                    while(lidx < ridx && nums[ridx] == nums[ridx+1]) ridx--;
//                }
//                else if(nums[lidx] + nums[ridx] < target_2sum)
//                    lidx++;
//                else
//                    ridx--;
//            }
//
//            while(j<nums.size()-2 && nums[j+1] == nums[j])
//                j++;
//        }
//
//        while(i<nums.size()-3 && nums[i+1] == nums[i])
//            i++;
//    }
//
//    return ans;
//}

