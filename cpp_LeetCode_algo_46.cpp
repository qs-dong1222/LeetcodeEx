#include <iostream>
#include <vector>

using namespace std;
void per(vector<int>& nums, int start, vector<vector<int>>& ans);
vector<vector<int>> permute(vector<int>& nums);

int main(){

    vector<int> nums =
    {1,2,3};

    vector<vector<int>> ans = permute(nums);

    for(auto eachvec:ans){
        for(auto each : eachvec){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}



vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;
    per(nums, 0, ans);
    return ans;
}

/*
    这一道题的原始数组没有重复元素. 可以用以下两种方法中任意一种解法来解决.
    但是, 以下两种解法都没办法解决 "原始数组含有重复元素时, 全排列结果有重复" 的情况.
    要想解决, 只有用hashset在存放时去除重复结果.
*/


/*
    solution 1: 在当前递归层中, 用swap的方式 来让各个位置上的元素打头.
                在下一层递归中, 把 除去上一层的打头元素 后剩下的元素,再走一遍同样的打头交换过程.

                简单来说, 就是把每一层递归看作是 "对于当前层打头位置, 选择不同打头元素" 的操作.
                在打头当前位置上把所有的能打头的都试一边. 再走到下一个位置, 把所有能打头的再试一遍.
*/
void per(vector<int>& nums, int start, vector<vector<int>>& ans){
    if(start>=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=start; i<(int)nums.size(); i++){
        swap(nums[start], nums[i]);
        per(nums, start+1, ans);
        swap(nums[start], nums[i]);
    }
}



/*
   solution 2: 传统的dfs
*/
void dfs(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& ans){
    if(curr.size() == nums.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=0; i<(int)nums.size(); i++){
        if(used[i]) continue;

        curr.push_back(nums[i]);
        used[i] = true;

        dfs(nums, used, curr, ans);

        used[i] = false;
        curr.pop_back();
    }
}
