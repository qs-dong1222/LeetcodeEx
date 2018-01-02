#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
void per(int numsize, int accNbr, unordered_map<int, int>& count, vector<int>& curr, vector<vector<int>>& ans);
vector<vector<int>> permuteUnique(vector<int>& nums);

int main(){

    vector<int> nums =
    //{1,1,2,3};
    {-1,2,0,-1,1,0,1};

    vector<vector<int>> ans = permuteUnique(nums);

    for(auto eachvec:ans){
        for(auto each : eachvec){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}



vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;

    unordered_map<int, int> count;
    for(int i=0;i<(int)nums.size(); i++){
        if(!count.count(nums[i])){
            count[nums[i]] = 1;
        }
        else{
            count[nums[i]]++;
        }
    }

    vector<int> curr;
    per(nums.size(), 0, count, curr, ans);

    return ans;
}


void per(int numsize, int accNbr, unordered_map<int, int>& count, vector<int>& curr, vector<vector<int>>& ans){
    if(accNbr>=numsize){
        ans.push_back(curr);
        return;
    }

    for(auto each:count){
        if(each.second <= 0)
            continue;

        curr.push_back(each.first);
        count[each.first]--;
        per(numsize, accNbr+1, count, curr, ans);
        count[each.first]++;
        curr.pop_back();
    }
}



