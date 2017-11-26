#include <iostream>
#include <vector>

using namespace std;

int G(vector<int>& nums, int lidx, int ridx);
int F(int rootIdx, vector<int>& nums);

int main(){

    vector<int> nums = {1,2,3,4};
    int ans = G(nums, 0, nums.size()-1);
    cout << ans << endl;
    return 0;
}


/*
此题解法思路实在是牛B，无言以对，五体投地:
F(idx,nums) 返回以nums[idx] 为根结点时，所有可能组成tree的个数
G(lidx, ridx, nums) 返回分别以 nums[lidx]~nums[ridx] 为根结点时，所有的可能组成tree的个数，即所有可能数
可以看出 F(idx,nums) = G(0, idx-1, nums) * G(idx+1, nums.size()-1, nums)
进而可以推断出 G(lidx, ridx, nums) = G(..)*G(..) + G(..)*G(..) + ... + G(..)*G(..)
*/

int G(vector<int>& nums, int lidx, int ridx){
    if(lidx >= ridx)
        return 1;

    int ans = 0;
    for(int i=lidx-1;i<=ridx-1;i++){
        ans += ( G(nums, lidx, i)*G(nums, i+2, ridx) );
    }
    return ans;
}

//int F(int rootIdx, vector<int>& nums){
//    return G(nums, 0, rootIdx-1) * G(nums, rootIdx+1, nums.size()-1);
//}


