#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int threeSumClosest(vector<int>& nums, int target);


int main(){

    vector<int> nums =
    //{1,-4,1,2,-1,2,1,2,-4,2,-4};
    //{1,1,1};
    //{-3,-2,-5,3,-4};
    //{1,2,4,8,16,32,64,128};
    {-1,0,1,1,55};

    //{-5,-4,-3,-2,3}

    cout << threeSumClosest(nums, 3) << endl;

    return 0;
}


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int absDiff = INT_MAX;
    int ans=0;
    for(int i=0; i<(int)nums.size()-2; i++){
        int newTarget = target - nums[i];
        int l=i+1;
        int r=(int)nums.size()-1;

        while(l < r){
            int newDiff = newTarget - nums[l] - nums[r];
            if(newDiff==0){
                return nums[i]+nums[l]+nums[r];
            }
            if(abs(newDiff) < absDiff){
                absDiff = abs(newDiff);
                ans = nums[i]+nums[l]+nums[r];
            }

            if(newDiff>0) l++; // need to bring up the sum -> increase l
            else r--; // need to bring down the sum -> decrease r
        }
    }

    return ans;
}
