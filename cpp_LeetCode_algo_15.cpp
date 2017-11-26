#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(){
    vector<int> nums = {3,0,-2,-1,1,2};

    vector<vector<int>> ans = threeSum(nums);

    for(auto eachArr: ans){
        for(auto each : eachArr){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}





vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<vector<int>> retAns;

    if(nums.size()<3){
        return retAns;
    }

    vector<int> valid;
    int lidx1, lidx2, ridx;
    for(lidx1=0;lidx1<=(int)nums.size()-3;lidx1++){
        lidx2 = lidx1 + 1;
        ridx = nums.size()-1;
        while(lidx2 < ridx){
            if(nums[lidx1] + nums[lidx2] + nums[ridx] == 0){
                valid.push_back(nums[lidx1]);
                valid.push_back(nums[lidx2]);
                valid.push_back(nums[ridx]);
                sort(valid.begin(), valid.end());
                ans.insert(valid);
                valid.clear();
                lidx2++;
            }
            else if(nums[lidx1] + nums[lidx2] + nums[ridx] < 0){
                lidx2++;
            }
            else{
                ridx--;
            }
        }
    }

    for(auto eachArr : ans){
        retAns.push_back(eachArr);
    }

    return retAns;

}
