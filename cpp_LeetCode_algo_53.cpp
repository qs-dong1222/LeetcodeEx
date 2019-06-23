#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums);


int main(){
    vector<int> nums =
    //{-2,1,-3,4,-1,2,1,-5,4};
    //{-1};
    {-2, 1};

    cout << maxSubArray(nums) << endl;
    return 0;
}



//int maxSubArray(vector<int>& nums) {
//    if(nums.empty()) return 0;
//
//    int ans = INT_MIN;
//    int maxV = INT_MIN;
//
//    for(int begin=0; begin<nums.size(); begin++){
//        maxV = max(maxV, nums[begin]);
//        // 以负数起始的subarray不可能是正确的
//        if(nums[begin]<0) continue;
//        int sum = 0;
//        for(int i=begin; i<nums.size(); i++){
//            sum += nums[i];
//            // 如果和为负，那还不如直接从后面那个开始，所以和为负就不用继续了
//            if(sum < 0){
//                begin = i;
//                break;
//            }
//            ans = max(sum, ans);
//        }
//    }
//    if(maxV <=0 ) return maxV;
//    return ans;
//}


/*
    这个题其实一种沿路打怪的思想. 正数说明补给血量, 负数代表耗血.
    当血量<0时, 人物就死了, 需要带着灵魂找一个补给点复活. 死的状态下,
    即使打了怪还是死. 所以死的时候, 血量一直保持为 0.

    总结来说, 人物去打怪, 打完怪更新血量, 如果血量<0, 说明死了, 血量可以更新为0.
    再接着打下一个怪.

    但是, 难点在于全为负数时, 还是要找一个最小的负数. 怎么办?
    让人物一开始就是血量为负, 在一步步更新就好了.
*/
int maxSubArray(vector<int>& nums) {
    int smax = INT_MIN;
    int sum = INT_MIN;
    for (auto num : nums) {
        if (sum < 0) {
            sum = 0;
        }
        sum += num;
        smax = max(smax, sum);

    }
    return smax;
}

