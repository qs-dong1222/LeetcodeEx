#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
int rob(vector<int>& nums);


int main(){

    vector<int> nums = {1,2,3,4,5};

    cout << rob(nums) << endl;

    return 0;
}



/*
solution 1: dp with array
*/
//int rob(vector<int>& nums) {
//    if(nums.empty()) return 0;
//
//    vector<int> f(nums.size()+1, 0);
//    f[1] = nums[0];
//
//    for(int i=2;i<(int)f.size();i++){
//        f[i] = max(f[i-2] + nums[i-1], f[i-1]);
//    }
//
//    return f[f.size()-1];
//}


/*
solution 2: dp without array, memory opt
*/
int rob(vector<int>& nums) {
    if(nums.empty()) return 0;

    int dp1 = 0;
    int dp2 = nums[0];
    int ans = nums[0];
    for(int i=1;i<(int)nums.size();i++){
        ans = max(dp1 + nums[i], dp2);
        dp1 = dp2;
        dp2 = ans;
    }

    return ans;
}
