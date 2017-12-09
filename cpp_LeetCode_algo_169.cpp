int majorityElement(vector<int>& nums) {
    int size = nums.size()>>1;
    unordered_map<int,int> ans;
    for(auto each:nums){
        if(!ans.count(each)){
            ans[each] = 1;
        }
        else{
            ans[each]++;
        }

        if(ans[each] > size){
            return each;
        }
    }

}
