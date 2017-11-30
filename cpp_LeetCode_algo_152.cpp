#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int maxProduct(vector<int>& nums);

int main(){
    vector<int> nums = {-3,0,1,-2};
    //{0, 3, 1, -7, 2, -3, 0, 1, -3};
    cout << maxProduct(nums) << endl;

    return 0;
}



/*
DP: o(~ n^2)
*/
//int maxProduct(vector<int>& nums) {
//    if(nums.empty()) return 0;
//    int ans = INT_MIN;
//
//    //vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 1));
//    int curr = 1;
//
//    for(int i=0; i<(int)nums.size(); i++){
//        if(nums[i]==1){
//            ans = max(ans, nums[i]);
//            continue;
//        }
//        for(int j=i; j<(int)nums.size(); j++){
//            if(i==j){
//                //dp[i][j] = nums[i];
//                curr = nums[i];
//            }
//            else{
//                //dp[i][j] = dp[i][j-1] * nums[j];
//                curr = curr * nums[j];
//            }
//            //ans = max(ans, dp[i][j]);
//            ans = max(ans, curr);
//        }
//    }
//
//    return ans;
//}


/*
maxProduct, minProduct都是用于记录之前所有值的成绩的最大/小值, 每次都更新, 还要与当前单个元素比
相当于说，我就是一个个硬乘，不撞南墙不回头，这个南墙就是0.
其实我们每次在当前值不是0的情况下，会记录两个值: 最大/小值。在下一回合硬乘，
如果下个数是负的，我们会更新也是负数的最小值，如果下个数是正的，我们会更新也是正数的最大值。
更新的值，必定是连续乘积的结果，不会断档。除非碰到一个0，所有数全变0，下一回合，我们会用当前
的非0正值去更新最大值，或用非0负值去更新最小值。并从此当前值重新计算乘积。

事实上，minProduct是用于 当出现负积时，为保证不断档且等待后续负负得正的一个备份。
*/
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    int maxProduct = nums[0], minProduct = nums[0], ans = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        int temp = maxProduct;
        maxProduct = max(max(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
        minProduct = min(min(temp * nums[i], minProduct * nums[i]), nums[i]);
        if (maxProduct > ans) {
            ans = maxProduct;
        }
    }
    return ans;
}
