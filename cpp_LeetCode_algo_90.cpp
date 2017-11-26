#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;
void combine(vector<int>& nums, int n, int d, int startIdx, vector<int>& curr, set<vector<int>>& ans);
vector<vector<int>> subsetsWithDup(vector<int>& nums) ;
int main(){
    vector<int> nums = {2,1,2,1,3};
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans = subsetsWithDup(nums);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each <<" ";
        }
        cout << endl;
    }

    return 0;
}



vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans;
    if(nums.empty()) return vector<vector<int>>(0,vector<int>(0));

    sort(nums.begin(), nums.end());

    vector<int> curr;
    for(int i=0;i<=nums.size();i++){
        curr.clear();
        combine(nums, nums.size(), nums.size()-i, 0, curr, ans);
    }

    vector<vector<int>> res;
    for(auto each : ans){
        res.push_back(each);
    }
    return res;
}


void combine(vector<int>& nums, int n, int d, int startIdx, vector<int>& curr, set<vector<int>>& ans){
    if(d==n){
        ans.insert(curr);
        return;
    }

    for(int i=startIdx; i<nums.size(); i++){
        curr.push_back(nums[i]);
        combine(nums, n, d+1, i+1, curr, ans);
        curr.pop_back();
    }
}
