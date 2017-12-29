#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int removeDuplicates(vector<int>& nums);

int main(){
    vector<int> v = {2,3,3,3,4,4,5,6};

    cout << removeDuplicates(v) << endl;

    for(auto each: v){
        cout << each << " ";
    }

    return 0;
}

int removeDuplicates(vector<int>& nums) {
    if((int)nums.size()<=1) return nums.size();

    for(int i=1;i<(int)nums.size();i++){
        if(nums[i]==nums[i-1]){
            nums.erase(nums.begin()+i);
            i--;
        }
    }

    return nums.size();
}
