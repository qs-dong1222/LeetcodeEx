#include <iostream>
#include <vector>

using namespace std;
void sortColors(vector<int>& nums);

int main(){
    vector<int> nums = {1,2,2,1,1,1,2,0,0};
    sortColors(nums);

    for(auto each : nums){
        cout << each <<" ";
    }
    return 0;
}






/*
    solution: 覆盖思想
*/
//void sortColors(vector<int>& nums){
//    vector<int> ans(nums.size(), 1);
//
//    int l=0, r=nums.size()-1;
//
//    for(int i=0; i<nums.size(); i++){
//        if(nums[i]==0){
//            ans[l] = 0;
//            l++;
//        }
//        else if(nums[i]==2){
//            ans[r] = 2;
//            r--;
//        }
//    }
//
//    nums = ans;
//}




/*
    solution: 利用位置排序的思想, 类似于 一号位放1, 二号位放2, 三号位放3, ...
              使得经过的每个位置都换到该放的数.
*/
void sortColors(vector<int>& nums){
    int zero_target_idx=0, two_target_idx=nums.size()-1;
    int i = 0;
    while(i<=two_target_idx){
        if(nums[i]==0){
            swap(nums[zero_target_idx], nums[i]);
            zero_target_idx++;
        }
        else if(nums[i]==2){
            swap(nums[two_target_idx], nums[i]);
            two_target_idx--;
            i--; // 这里--的目的是保持 i 不动,
                 // 原因: 如果换过去的是2, 换回来的是0,
                 // 那么0应该还有一次向前换的机会, 否则就会错过这个换回来的0
        }
        i++;
    }
}



