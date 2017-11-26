#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;


vector<int>& BubbleSort(vector<int>& nums){
    int arrSize = nums.size();
    int i,j,tmp;
    for(i=0;i<arrSize-1;i++){
        for(j=0;j<arrSize-i-1;j++){
            if(nums[j+1] < nums[j]){
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
    return nums;
}



vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    int i;
    vector<int> ret(2);
    unordered_map<int,int> val_idx_dict;

    int complement;
    for(i=0;i<size;i++){
        complement = target - nums[i];

        if(val_idx_dict.find(complement) != val_idx_dict.end()){
            ret[0] = val_idx_dict[complement];
            ret[1] = i;
            return ret;
        }
        else{
            val_idx_dict[nums[i]] = i;
        }
    }

    ret[0] = -1;
    ret[1] = -1;
    return ret;
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
