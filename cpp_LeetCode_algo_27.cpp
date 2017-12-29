#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int>& nums, int val);

int main(){
    vector<int> nums = {3,2,2,3};

    cout << removeElement(nums, 3) << endl;

    for(auto each:nums){
        cout << each << " ";
    }

    return 0;
}









int removeElement(vector<int>& nums, int val) {
    if(nums.empty()) return nums.size();

    for(int i=0;i<(int)nums.size();i++){
        if(nums[i]==val){
            nums.erase(nums.begin()+i);
            i--;
        }
    }

    return nums.size();
}









//int removeElement(vector<int>& nums, int val) {
//    if(nums.empty()) return 0;
//
//    vector<int>::iterator it = nums.begin();
//
//    int i=0;
//    while(i<(int)nums.size()){
//        if(nums[i]==val){
//            nums.erase(i+it);
//        }
//        else{
//            i++;
//        }
//    }
//
//    return nums.size();
//}
