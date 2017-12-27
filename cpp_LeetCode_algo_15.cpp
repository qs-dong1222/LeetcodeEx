#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(){
    vector<int> nums =
    //{3,0,-2,-1,1,2};
    {-1, 0, 1, 2, -1, -4};
    //{0,1};

    vector<vector<int>> ans = threeSum(nums);

    for(auto eachArr: ans){
        for(auto each : eachArr){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}



vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty() || nums.size()<3) return ans;

    sort(nums.begin(), nums.end());

    int target = 0;

    for(int i=0;i<(int)nums.size()-2;i++){
        int newTarget = target - nums[i];
        int l = i+1;
        int r = nums.size()-1;
        while(l < r){
            if(nums[l] + nums[r] > newTarget){
                r--;
            }
            else if(nums[l] + nums[r] < newTarget){
                l++;
            }
            else{
                vector<int> curr = {nums[i], nums[l], nums[r]};
                ans.push_back(curr);
                while(l<r && nums[l+1]==nums[l]) l++;
                l++;
                while(l<r && nums[r-1]==nums[r]) r--;
                r--;
            }
        }

        while(i<(int)nums.size()-2 && nums[i+1]==nums[i]) i++;
        // for loop will i++ by itself
    }

    return ans;
}
