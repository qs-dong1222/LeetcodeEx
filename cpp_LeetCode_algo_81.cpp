#include <iostream>
#include <vector>

using namespace std;
bool search(vector<int>& nums, int target);
int main(){

    vector<int> nums = {1,1,3,1};

    cout << search(nums, 3) <<endl;

    return 0;
}



bool search(vector<int>& nums, int target) {
    int lidx = 0, ridx = nums.size()-1, mid;

    while(lidx<=ridx){
        mid = lidx + (ridx-lidx)/2;
        if(nums[mid] == target) return true;

        else if(nums[mid] > nums[ridx]){
            if(target < nums[lidx]){
                lidx = mid+1;
            }
            else if(target == nums[lidx])
                return true;
            else{
                if(target < nums[mid]){
                    ridx = mid-1;
                }
                else{
                    lidx = mid+1;
                }
            }
        }
        else if(nums[mid] < nums[ridx]){
            if(target == nums[ridx]){
                return true;
            }
            else if(target > nums[ridx]){
                ridx = mid - 1;
            }
            else{
                if(target < nums[mid]){
                    ridx=mid-1;
                }
                else{
                    lidx = mid +1;
                }
            }
        }
        else
            ridx--;
    }

    return false;
}
