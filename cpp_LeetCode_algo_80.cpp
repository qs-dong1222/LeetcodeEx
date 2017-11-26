int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int ans = 1;
    int count = 1;
    int pre = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]==pre){
            if(count < 2){
                count++;
                ans++;
            }
            else{
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        else{
            count = 1;
            ans++;
        }
        pre = nums[i];
    }

    return ans;
}
