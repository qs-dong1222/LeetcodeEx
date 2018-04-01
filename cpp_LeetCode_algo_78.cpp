#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> subsets(vector<int>& nums);
void com(vector<int>& nums, int d, int start, int n, vector<int>& curr, vector<vector<int>>& ans);

void helper(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans);

vector<int> genVec(int n);

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);


    for(auto eachRow : ans){
        for(auto each: eachRow){
            cout << each << " ";
        }
        cout <<"\n------------"<<endl;
    }

    return 0;
}



vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;

    helper(nums, 0, curr, ans);

    return ans;
}




void helper(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans){
    if(start>=(int)nums.size()){
        ans.push_back(curr);
        return;
    }

    // collect this nums[start], go to next number
    curr.push_back(nums[start]);
    helper(nums, start+1, curr, ans);
    curr.pop_back();

    // dont need this nums[start], go to next number
    helper(nums, start+1, curr, ans);
}









//vector<vector<int>> subsets(vector<int>& nums) {
//    vector<vector<int>> ans;
//    vector<int> curr;
//
//    for(int i=0;i<=nums.size();i++){
//        com(nums, nums.size()-i, 0, nums.size(), curr, ans);
//    }
//
//    return ans;
//}
//
//
//void com(vector<int>& nums, int d, int start, int n, vector<int>& curr, vector<vector<int>>& ans){
//    if(d==n){
//        ans.push_back(curr);
//        return;
//    }
//
//    for(int i=start; i<nums.size(); i++){
//        curr.push_back(nums[i]);
//        com(nums, d+1, i+1, n, curr, ans);
//        curr.pop_back();
//    }
//}
//
//vector<int> genVec(int n){
//    vector<int> v;
//    for(int i=1;i<=n;i++)
//        v.push_back(i);
//    return v;
//}
