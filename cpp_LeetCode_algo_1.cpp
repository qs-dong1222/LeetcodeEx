#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    if(nums.size()<=1) return ans;

    unordered_map<int,int> val_idx;
    for(int i=0;i<nums.size();i++){
        int leftval = target - nums[i];
        if(val_idx.count(leftval)){
            ans.push_back(val_idx[leftval]);
            ans.push_back(i);
            return ans;
        }
        else{
            val_idx[nums[i]] = i;
        }
    }
}

int main()
{
    vector<int> aaa = {3,2,4};

    vector<int> ret = twoSum(aaa, 6);

    for(auto it=ret.begin();it!=ret.end();it++){
        cout<<*it<<endl;
    }


    return 0;
}
