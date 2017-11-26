int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int a_idx, b_idx, c_idx;
    int ans=0;
    for(c_idx=nums.size()-1;c_idx>=2;c_idx--) {
        a_idx = 0;
        b_idx = c_idx-1;
        while(a_idx<b_idx){
            if(nums[a_idx]+nums[b_idx]>nums[c_idx]) {
                ans += b_idx - a_idx;
                b_idx--;
            }
            else{
                a_idx++;
            }
        }
    }

    return ans;

}
