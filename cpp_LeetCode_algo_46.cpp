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
