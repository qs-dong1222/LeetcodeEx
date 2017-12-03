#include <iostream>
#include <vector>

using namespace std;
int maximumGap(vector<int>& nums);

int main(){
    vector<int> nums = {1,1,1,1,1,5,5,5,5,5};
    cout << maximumGap(nums) << endl;

    return 0;
}


/*
bucket sort
*/
int maximumGap(vector<int>& nums) {
    if((int)nums.size()<2) return 0;

    int numMin = INT_MAX;
    int numMax = INT_MIN;
    for(auto each : nums){
        numMin = min(each, numMin);
        numMax = max(each, numMax);
    }

    int bucketSize = (numMax-numMin)/(nums.size()-1)==0? 1:(numMax-numMin)/(nums.size()-1);
    int NbrBuckets = (numMax-numMin)/bucketSize==0? 1:(numMax-numMin)/bucketSize;

    vector<int> bucketMin(NbrBuckets, INT_MAX); // record max for each bucket
    vector<int> bucketMax(NbrBuckets, INT_MIN); // record min for each bucket
    vector<int> bucketHasVal(NbrBuckets, false);

    for(int i=0;i<(int)nums.size();i++){
        int bucketIdx = (nums[i]-numMin)/bucketSize;
        bucketHasVal[bucketIdx] = true;
        bucketMin[bucketIdx] = min(nums[i], bucketMin[bucketIdx]);
        bucketMax[bucketIdx] = max(nums[i], bucketMax[bucketIdx]);
    }

    int maxGap = 0;
    int prevMax = bucketMax[0];
    for(int i=1;i<NbrBuckets;i++){
        if(bucketHasVal[i]){
            maxGap = max(bucketMin[i]-prevMax, maxGap);
            prevMax = bucketMax[i];
        }
    }

    return maxGap;
}






/*
counting sort : TLE
*/
//int maximumGap(vector<int>& nums) {
//    if((int)nums.size()<2) return 0;
//
//    int numMin = INT_MAX;
//    int numMax = INT_MIN;
//    for(auto each : nums){
//        numMin = min(each, numMin);
//        numMax = max(each, numMax);
//    }
//
//    vector<int> count(numMax-numMin+1, 0);
//
//    for(auto each : nums){
//        count[each-numMin]++;
//    }
//
//    int maxGap = 0;
//    int prevIdx = 0;
//    for(int i=1;i<(int)count.size();i++){
//        if(count[i] > 0){
//            maxGap = max(i-prevIdx, maxGap);
//            prevIdx = i;
//        }
//    }
//
//    return maxGap;
//}
