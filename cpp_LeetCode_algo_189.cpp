#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
void rotate(vector<int>& nums, int k);
void showArr(vector<int>& nums);

int main(){

    vector<int> nums = {1,2,3,4,5,6,7};

    rotate(nums, 3);

    showArr(nums);

    return 0;
}

void rotate(vector<int>& nums, int k) {
    if(nums.empty()) return;

    k = k % nums.size();
    reverse(nums.begin(), nums.end());

    vector<int>::iterator it = nums.begin();

    advance(it, k);
    reverse(nums.begin(), it);
    reverse(it, nums.end());
}


void showArr(vector<int>& nums){
    for(auto each:nums){
        cout << each << " ";
    }
    cout << endl;
}


//1 2 3 4 -0
//4 1 2 3 -1
//3 4 1 2 -2
//2 3 4 1 -3
//1 2 3 4 -4
//4 1 2 3 -5  -> 5 % nums.size() = k


