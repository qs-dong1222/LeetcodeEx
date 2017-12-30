#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void nextPermutation(vector<int>& nums);
int main(){
    vector<int> nums =
    //{5,4,3,2,1};
    //{1,3,6,2,1};
    //{1,2,3};
    {2,1,3};
    //{1,1};

    nextPermutation(nums);

    for(auto each:nums){
        cout << each << " ";
    }

    return 0;
}


/*
solution:
这道题是一道观察规律的题，如果摸索不出来规律，其他的也就白扯了。
一般观察时先举几个例子:
original: 1 2 3 4 6 5
next:     1 2 3 5 4 6

original: 1 3 6 3 3 2 1
next:     1 6 1 2 3 3 3

我们看到第一个例子里我们动的是4，第二个例子我们动的是第一个3.
我们的根本目的是找到下一个最接近original且比original大的值.
而数字排列有个特点，按升序排列的数字一定是当且所有数字排列中值最小的.
相反降序排列一定是最大的。比如123, 升序排列的123肯定是三个位上排列的最小值组合.

如果我们想找下一个大值，肯定定不能从最高位开始变，否则最高位一变，整个数就大了很多.
而original前半部分正好是升序排列，后半部分正好是降序排列。降序排列的部分肯定是那几位的最大可能值。
我们要想增大整个数，肯定要在降序部分的基础上增大数值。而这里增大数值只能靠换位的方式，所以不可避免
的，我们肯定要在降序部分的前一位(即升序的最后一位)进行变位，从而达到进位增大的效果。
那么好了，我们知道要变哪一位了，就是从后向前找第一个变小的数就是要变的。
那么变成什么数？
我们的目的是增大original，但增大的步子又不能迈的太大。所以肯定要换一个比原来的数刚刚好大一点的数。
那么就从后往前找，找到第一个比待变位数值大的数，交换即可。
最后，为了保证增大的步子又不能迈的太大，我们还要变位处后面那几位升序排列一下，以保证后半部分的值
是最小的。
*/
void nextPermutation(vector<int>& nums){
    if(nums.empty()) return;

    int ridx = nums.size()-1;
    while(ridx>0 && nums[ridx-1]>=nums[ridx]){
        ridx--;
    }

    if(ridx==0){
        sort(nums.begin(), nums.end());
        return;
    }

    // nums[ridx-1] needs to change
    int pivot = nums[ridx-1];
    int r = nums.size()-1;
    while(nums[r]<= pivot){
        r--;
    }

    swap(nums[ridx-1], nums[r]);
    sort(nums.begin()+ridx,nums.end());
}






//void nextPermutation(vector<int>& nums) {
//    if(nums.empty()) return;
//    int revIdx = nums.size()-1;
//    int lidx, ridx = nums.size()-1;
//    while(nums[revIdx-1] >=  nums[revIdx] && revIdx>0)
//        revIdx--;
//    if(revIdx == 0){
//        sort(nums.begin(), nums.end());
//    }
//    else{
//        lidx = revIdx-1;
//        while(nums[ridx] <= nums[lidx]) ridx--;
//        swap(nums[lidx], nums[ridx]);
//        sort(nums.begin()+lidx+1, nums.end());
//    }
//}
