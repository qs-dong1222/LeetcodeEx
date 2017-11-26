#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> subsets(vector<int>& nums);
void com(vector<int>& nums, int d, int start, int n, vector<int>& curr, vector<vector<int>>& ans);
vector<int> genVec(int n);

int main(){

    return 0;
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;

    for(int i=0;i<=nums.size();i++){
        com(nums, nums.size()-i, 0, nums.size(), curr, ans);
    }

    return ans;
}


void com(vector<int>& nums, int d, int start, int n, vector<int>& curr, vector<vector<int>>& ans){
    if(d==n){
        ans.push_back(curr);
        return;
    }

    for(int i=start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        com(nums, d+1, i+1, n, curr, ans);
        curr.pop_back();
    }
}

vector<int> genVec(int n){
    vector<int> v;
    for(int i=1;i<=n;i++)
        v.push_back(i);
    return v;
}
