#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findKthSmallest(int k, vector<int>& nums1, int start1, vector<int>& nums2, int start2);






int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout.precision(6);
    cout <<findMedianSortedArrays(nums1, nums2)<< endl;
//    cout << findKthSmallest(5, nums1, 0, nums2, 0) << endl;

    return 0;
}


// k starts from 1th
double findKthSmallest(int k, vector<int>& nums1, int start1, vector<int>& nums2, int start2){
    if(nums1.empty() && nums2.empty()) return NULL;

    int size1 = nums1.size() - start1;
    int size2 = nums2.size() - start2;
    if(size1 > size2) return findKthSmallest(k, nums2, start2, nums1, start1);

    if(size1==0){
        return nums2[start2+k-1];
    }
    if(k==1){
        return min(nums1[start1], nums2[start2]);
    }

    auto nA = min(k/2, size1); // pick k/2 elements from nums1, if size1<k/2, we pick all elements
    auto nB = k - nA; // pick rest of elements from nums2

    if(nums1[start1+nA-1] < nums2[start2+nB-1]){
        // nums1[0 : nA-1] are within merge array[0 : k-1], discard nums[0 : nA-1]
        return findKthSmallest(k-nA, nums1, start1+nA, nums2, start2);
    }
    else if(nums1[start1+nA-1] > nums2[start2+nB-1]){
        return findKthSmallest(k-nB, nums1, start1, nums2, start2+nB);
    }
    else{
        return nums1[start1+nA-1];
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int totSize = nums1.size() + nums2.size();

    if(totSize%2 == 1){ // odd size
        return findKthSmallest(totSize/2+1, nums1, 0, nums2, 0);
    }
    else{
        //cout << findKthSmallest(totSize/2, nums1, nums2) << endl;
        //cout << findKthSmallest(totSize/2+1, nums1, nums2) << endl;
        return (findKthSmallest(totSize/2, nums1, 0, nums2, 0) + findKthSmallest(totSize/2+1, nums1, 0, nums2, 0)) * 0.5;
    }
}





//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//    int size1 = nums1.size();
//    int size2 = nums2.size();
//    int halfSize = (size1+size2+1)/2;
//
//    // pick first n1 elements from nums1, first n2 elements from nums2, which sum = halfSize
//    // suppose size1 < size2
//    if(size1>size2) return findMedianSortedArrays(nums2, nums1);
//
//    int lsp = 0;
//    int rsp = size1;
//    int midsp;
//    int nElem1 = 0;
//    int nElem2 = 0;
//
//    while(lsp < rsp){
//        midsp = (rsp+lsp+1)/2;
//        nElem1 = midsp-lsp;
//        nElem2 = halfSize-nElem1;
//
//        if(nums1[nElem1-1] > nums2[nElem2] && nElem2<size2){ // picked too much from nums1
//            rsp = midsp-1;
//        }
//        else if(nums2[nElem2-1] > nums1[nElem1] && nElem1<size1){ // pick too less from nums1
//            lsp = midsp;
//        }
//        else{
//            break;
//        }
//    }
//
//
//    // if reach here, we have 2 possibilities:
//    // 1. all elements in nums1 are picked -> lsp = size1
//    // 2. no elements in nums1 is picked -> rsp = 0
//    // 3. found elements needed in nums1 and nums2
//
//    if(nElem1 = size1){ //all elements in nums1 are picked
//        if(halfSize-size1 == 0){ // no elements need from nums2
//            if((size1+size2) % 2==1){
//                return nums1[size1-1];
//            }
//            else{
////                double a = nums1[size1-1] + nums2[0];
////                a *= 0.5;
//                return (nums1[size1-1] + nums2[0])*0.5;
//            }
//        }
//        else{ // need some elements from nums2
//            if((size1+size2) % 2==1){
//                return nums2[halfSize-size1-1];
//            }
//            else{
//                return (nums2[halfSize-size1-1] + nums2[halfSize-size1])*0.5;
//            }
//        }
//    }
//
//    if(nElem1==0){ // no elements in nums1 is picked, all should be from nums2
//        if((size1+size2) % 2==1){
//            return nums2[halfSize-1];
//        }
//        else{
//            return (nums2[halfSize-1] + nums2[halfSize])*0.5;
//        }
//    }
//
//
//    if( (size1+size2) % 2==1 ){
//        return max(nums1[nElem1-1], nums2[nElem2-1]);
//    }
//    else{
//        return (max(nums1[nElem1-1], nums2[nElem2-1])+min(nums1[nElem1], nums2[nElem2]))*0.5;
//    }
//}
