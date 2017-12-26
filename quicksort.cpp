#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <cstdlib>

using namespace std;
void QuickSort(vector<int>& nums, int lidx, int ridx);

void printArr(vector<int>& nums){
    for(auto each : nums){
        cout << each << " ";
    }
    cout << endl;
}


int main(){

    vector<int> nums =
    //{-2,-1,0,1,2,3};
    //{6,5,4,3,2,1};
    //{3,5,0,-2,1,6,0,0};
    //{3,5,0,-2,1,6,0,4,8,0,7,4,4};
    //{0,1,0,1,0,1,0,1,0,1};
    {5,4,3,2,6};
    QuickSort(nums, 0, nums.size()-1);

    printArr(nums);

    return 0;
}


void QuickSort(vector<int>& nums, int lidx, int ridx){
    if(lidx>=ridx) return;

    // randomize the pivot
    auto randIdx = lidx + (rand()%(ridx-lidx+1));
    swap(nums[randIdx], nums[ridx]);

    int pivot = nums[ridx];
    auto r = ridx-1;
    auto l = lidx;
    while(l <= r){
        // 主旨就是: 一定要当l, r 真正交叉的时候(重叠不算), 结束扫描
        while(l <= r && nums[l] < pivot){
            l++;
        }

        while(l <= r && nums[r] >= pivot){
            r--;
        }

        if(l <= r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        //printArr(nums);
    }

    // swap the pivot, now the pivot is in the middle position of 'l' and array is spit by the pivot
    swap(nums[l], nums[ridx]);

    QuickSort(nums, lidx, l-1);
    QuickSort(nums, l+1, ridx);
}




//void QuickSort(vector<int>& nums, int lidx, int ridx){
//    if(nums.empty() || lidx>=ridx) return;
//
//    auto leftBound = lidx;
//    auto rightBound = ridx;
//    auto ref = nums[lidx + (rand()%(ridx-lidx+1))];
//    while(lidx < ridx){
//        while( lidx<ridx && nums[lidx]<ref ){
//            lidx++;
//        }
//        while( lidx<ridx && nums[ridx]>ref ){
//            ridx--;
//        }
//
//        if(lidx < ridx){
//            // no cross
//            swap(nums[lidx], nums[ridx]);
//            lidx++;
//            ridx--;
//        }
//
//        printArr(nums);
//    }
//
//    QuickSort(nums, leftBound, lidx-1);
//    QuickSort(nums, lidx+1, rightBound);
//}





