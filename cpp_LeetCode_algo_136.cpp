// 异或运算 满足交换律和结合律

int singleNumber(vector<int>& nums) {
    int ans = nums[0];
    for(int i=1;i<nums.size();i++){
        ans ^= nums[i];
    }
    return ans;
}
