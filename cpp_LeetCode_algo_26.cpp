#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int removeDuplicates(vector<int>& nums);

int main(){
    vector<int> v = {0,0,0,0,0};
    sort(v.begin(), v.end());

    cout << removeDuplicates(v) << endl;

    for(auto each: v){
        cout << each << endl;
    }

    return 0;
}



int removeDuplicates(vector<int>& nums) {
    vector<int>::iterator it=nums.begin();
    int i;
    for(i=0; i<(int)nums.size()-1; i++){
        while(nums[i]==nums[i+1]){
            nums.erase(i+it);
            if(nums.size() == 1) break;
            if(i==(int)nums.size()-1) break;
        }
    }
    if(nums[nums.size()-1] == nums[nums.size()-2]) nums.erase(nums.size()-1+it);
    return nums.size();
}
