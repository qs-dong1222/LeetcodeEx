#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

void combineWithSet(vector<int>& nums, int start, vector<int>& curr, set<vector<int>>& ans);
void combineHasDup(vector<int>& nums, set<vector<int>>& ans);


vector<vector<int>> subsetsWithDup(vector<int>& nums) ;
int main(){
    vector<int> nums = {2,1,2,1,3};
    vector<vector<int>> ans = subsetsWithDup(nums);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each <<" ";
        }
        cout << endl;
    }

    return 0;
}


/*
    思路比较直接, 先用针对有重复元素的组合方法去找出所有子组合, 再由set换成数组存储
*/
void combineWithSet(vector<int>& nums, int start, vector<int>& curr, set<vector<int>>& ans){
    if(start == (int)nums.size()){
        ans.insert(curr);
        return;
    }

    curr.push_back(nums[start]);
    combineWithSet(nums, start+1, curr, ans);
    curr.pop_back();
    combineWithSet(nums, start+1, curr, ans);
}


void combineHasDup(vector<int>& nums, set<vector<int>>& ans){
    sort(nums.begin(), nums.end());
    vector<int> curr;
    combineWithSet(nums, 0, curr, ans);
}



vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans;
    if(nums.empty()) return vector<vector<int>>(0,vector<int>(0));

    combineHasDup(nums, ans);

    vector<vector<int>> res;
    for(auto each : ans){
        res.push_back(each);
    }
    return res;
}



