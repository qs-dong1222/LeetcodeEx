#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main(){
    vector<int> nums =
//    {1,1,2,2,2,3};
    {1,1,1,2};

    cout << removeDuplicates(nums) << endl;

    for(auto each : nums){
        cout << each << " ";
    }

    return 0;
}



int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int cnt = 1;
    int prev = nums[0];

    for(int i=1; i<(int)nums.size(); i++){
        if(prev == nums[i]){
            if(cnt == 1){
                // 2nd duplicative number
                cnt++;
            }
            else{
                // more than twice duplicative number
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        else{ // meet a new number
            cnt = 1;
            prev = nums[i];
        }
    }

    return nums.size();
}























//int removeDuplicates(vector<int>& nums) {
//    if(nums.empty()) return 0;
//
//    int ans = 1;
//    int count = 1;
//    int pre = nums[0];
//    for(int i=1;i<nums.size();i++){
//        if(nums[i]==pre){
//            if(count < 2){
//                count++;
//                ans++;
//            }
//            else{
//                nums.erase(nums.begin()+i);
//                i--;
//            }
//        }
//        else{
//            count = 1;
//            ans++;
//        }
//        pre = nums[i];
//    }
//
//    return ans;
//}
