#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
void allSubSets(vector<int>& nums, int startIdx, vector<int>& curr, vector<vector<int>>& ans);

int main(){

    vector<int> nums = {1,2,3};

    vector<int> curr;
    vector<vector<int>> ans;

    allSubSets(nums, 0, curr, ans);

    for(auto eachr:ans){
        for(auto each : eachr){
            cout << each << " ";
        }
        cout <<endl;
    }

    return 0;
}


void allSubSets(vector<int>& nums, int startIdx, vector<int>& curr, vector<vector<int>>& ans){
    if(startIdx >= nums.size()){
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[startIdx]);
    allSubSets(nums, startIdx+1, curr, ans);
    curr.pop_back();
    allSubSets(nums, startIdx+1, curr, ans);
}


