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


void sortColors(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    int lidx=0, ridx=nums.size()-1;
    for(auto each : nums){
        if(each == 0){
            ans[lidx] = 0;
            lidx++;
        }
        else if(each == 2){
            ans[ridx] = 2;
            ridx--;
        }
    }

    nums = ans;
}

