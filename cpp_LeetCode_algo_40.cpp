#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
void DFS(vector<int>& candidates, int target, int start_idx, vector<int>& temp, vector<vector<int>>& ans);

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<int> curr;
    vector<vector<int>> ans;

    return 0;
}




vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
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
        // 这一步continue在这里很关键
        // 由于题目要求是不能出现重复答案, 那么对于 nums={1,1,2,3}, target=6 这种输入
        // 由于有两个'1', 在组合数抽取时会取第一个'1'和第二个'1'分别构成[1,2,3]
        // 为解决这种问题, 在当前答案位置上(当前递归层中), 如果我们之前已经试过
        // 一次'1'了, 那就没必要再试一次'1'了. 当然第一次的那个'1'是必须要试的
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        if(target-nums[i]<0){
            return;
        }

        // collect this num
        curr.push_back(nums[i]);
        // if use "i+1" for next start index, we will not allow repetitive collection at the same index
        dfs(nums, i+1, target-nums[i], curr, ans);
        curr.pop_back();
    }
}
