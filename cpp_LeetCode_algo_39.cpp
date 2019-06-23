#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans);
vector<vector<int>> combinationSum(vector<int>& nums, int target);

int main(){
    vector<int> nums =
    //{2,3,4,5,6,7};
    {5,4,6,2,7,3};

    vector<vector<int>> ans = combinationSum(nums, 7);

    for(auto a : ans){
        for(auto b : a){
            cout<< b << " ";
        }
        cout<< endl;
    }

    return 0;
}



/*
    这个题的难点在于不能存储重复的组合结果.
    [2,2,3] 和 [2,3,2] 会被视作是一种组合.
    这其实就是求排列数, 去除排列结果中 "排序后相同的" 的自结果.
    这其实有点难.
    举个例子, 从 [5,6,1,3] 取三个数
    第一次试验:
    数(1): [5,6,1,3] -> 5打头
    数(2): [5,6,1,3] -> 5打头
    数(3): [5,6,1,3] -> 5, 6, 1, 3 随便取

    第二次试验:
    数(1): [5,6,1,3] -> 5打头
    数(2): [5,6,1,3] -> 这次以6打头
    数(3): [5,6,1,3] -> 如果这里再取5的话, 就有[5,6,5], 和[5,5,6] 冲突.
    冲突的原因是: [5,6,5] 相当于 数(2)和数(3) 的打头顺序换了一下, 或者说 数(2)和数(3) 做了一次内部排列.

    怎么避免这种内部排列?
    因为这里允许一个元素被重复选择, 所以在递归层里面, 下一层递归必须要允许能选到当前层的数.
    但在下一层递归中, 如果不去拿当前层之前已经"彻底"尝试过的数, 就可以避免内部排列.
*/
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;

    vector<int> curr;

    dfs(nums, 0, target, curr, ans);
    return ans;
}

void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans){
    if(target == 0){
        ans.push_back(curr);
        return;
    }

    if(target < 0){
        return;
    }

    for(int i=start; i<(int)nums.size(); i++){
        curr.push_back(nums[i]);
        dfs(nums, i, target-nums[i], curr, ans);
        curr.pop_back();
    }
}


