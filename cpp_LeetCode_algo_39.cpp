#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans);
vector<vector<int>> combinationSum(vector<int>& nums, int target);

int main(){
    vector<int> nums =
    //{2,3,4,5,6,7};
    {2,3,4,5,6,7};

    vector<vector<int>> ans = combinationSum(nums, 7);

    for(auto a : ans){
        for(auto b : a){
            cout<< b << " ";
        }
        cout<< endl;
    }

    return 0;
}



vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;

    vector<int> curr;
    sort(nums.begin(), nums.end());

    dfs(nums, 0, target, curr, ans);
    return ans;
}



void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans){
    if(target==0 && start<=(int)nums.size()){
        ans.push_back(curr);
        return;
    }
    else if(start>=(int)nums.size()){
        return;
    }

    for(int i=start;i<(int)nums.size();i++){
        if(target-nums[i]<0){
            return;
        }

        // collect this num
        curr.push_back(nums[i]);
                // if use "i+1" for next start index, we will not allow repetitive collection at the same index
                //dfs(nums, i+1, target-nums[i], curr, ans);
        // if use "i" for next start index, we will allow repetitive collection at the same index
        dfs(nums, i, target-nums[i], curr, ans);
        curr.pop_back();

        // next for loop is the case where we do not collect this current number but try with next number
    }
}
