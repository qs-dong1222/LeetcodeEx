#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = fourSum(nums, 0);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty()){
        return ans;
    }

    sort(nums.begin(), nums.end());

    vector<int> tmp;
    int target_2sum;
    int lidx, ridx;

    for(int i=0; i<nums.size()-3; i++){
        for(int j=i+1; j<nums.size()-2; j++){
            target_2sum = target - nums[i] - nums[j];
            lidx = j+1;
            ridx = nums.size()-1;

            while(lidx < ridx){
                if(nums[lidx] + nums[ridx] == target_2sum){
                    tmp = {nums[i], nums[j], nums[lidx], nums[ridx]};
                    ans.push_back(tmp);
                    lidx++;
                    while(lidx < ridx && nums[lidx] == nums[lidx-1]) lidx++;
                    while(lidx < ridx && nums[ridx] == nums[ridx+1]) ridx--;
                }
                else if(nums[lidx] + nums[ridx] < target_2sum)
                    lidx++;
                else
                    ridx--;
            }

            while(j<nums.size()-2 && nums[j+1] == nums[j])
                j++;
        }

        while(i<nums.size()-3 && nums[i+1] == nums[i])
            i++;
    }

    return ans;
}



//void changeMinIdx(vector<int>& nums, int& idx1, int& idx2, int& idx3){
//    int idxA, idxB, idxC;
//    idxA = nums[idx1] - nums[idx1-1] <= nums[idx2] - nums[idx2-1] ? idx1 : idx2;
//    idxB = nums[idx2] - nums[idx2-1] <= nums[idx3] - nums[idx3-1] ? idx2 : idx3;
//    idxC = nums[idxA] - nums[idxA-1] <= nums[idxB] - nums[idxB-1] ? idxA : idxB;
//    if(idxC == idx1) idx1--;
//    if(idxC == idx2) idx2--;
//    if(idxC == idx3) idx3--;
//}
