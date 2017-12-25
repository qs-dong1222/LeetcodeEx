#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) ;

//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//    int size1 = nums1.size();
//    int size2 = nums2.size();
//    int halfSize = (size1+size2+1)/2;
//
//    // pick first n1 elements from nums1, first n2 elements from nums2, which sum = halfSize
//    // suppose size1 < size2
//    if(size1>size2) return findMedianSortedArrays(nums2, nums1);
//
//    int lidx = 0; // left split pos, partition 0th~(lsp-1)th, (lsp)th~end
//    int ridx = nums1.size()-1; // right split pos, similar as above
//
//    while(lidx <= ridx){
//        int mid = lidx+(ridx-lidx)/2;
//        int n1 = mid-lidx+1;
//        int n2 = halfSize - n1;
//
//        if(nums1[n1-1] > nums2[n2]){// picked too much elements from nums1
//            ridx = mid-1;
//        }
//        else if(nums2[n2-1] > nums1[n1]){ // picked too much elements from nums2
//            lidx = mid+1;
//        }
//        else{ // found the correct boundary
//            if( (size1+size2) % 2 == 1){
//                return (double)max(nums1[n1-1], nums2[n2-1]);
//            }
//            else{
//                double a = (double)max(nums1[n1-1], nums2[n2-1]);
//                double b = (double)min(nums1[n1], nums2[n2]);
//                return (a+b)*0.5;
//            }
//        }
//    }
//
//    // nums1 doesn't provide any elements, it has nothing to do with nums1
//    if(ridx<=0){
//        if( (size1+size2) % 2 == 1){
//            return (double)nums2[halfSize-1];
//        }
//        else{
//            return (nums2[halfSize-1]+nums2[halfSize])*0.5;
//        }
//    }
//
//    // nums1 are all picked
//    if(lidx>=size1){
//        if(halfSize-size1==0){
//            if((size1+size2) % 2 == 1){
//                return (double)nums1[size1-1];
//            }
//            else{
//                return (nums1[size1-1]+nums2[0])*0.5;
//            }
//        }
//        else{
//            if((size1+size2) % 2 == 1){
//                return (double)nums2[halfSize-size1-1];
//            }
//            else{
//                return (nums2[halfSize-size1-1]+nums2[halfSize-size1-2])*0.5;
//            }
//        }
//    }
//
////    // nums1 provides all elements, it has nothing to do with nums2
////    if(size1==size2){
////        return (nums1[size1-1]+nums2[0])*0.5;
////    }
//
//
//}






int main(){
    vector<int> v1 = {3};
    vector<int> v2 = {1,2};

    cout.precision(6);
    cout <<findMedianSortedArrays(v1,v2)<< endl;

    return 0;
}



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int halfSize = (size1+size2+1)/2;

    // pick first n1 elements from nums1, first n2 elements from nums2, which sum = halfSize
    // suppose size1 < size2
    if(size1>size2) return findMedianSortedArrays(nums2, nums1);

    int lsp = 0;
    int rsp = size1;
    int midsp;
    int nElem1 = 0;
    int nElem2 = 0;

    while(lsp < rsp){
        midsp = (rsp+lsp+1)/2;
        nElem1 = midsp-lsp;
        nElem2 = halfSize-nElem1;

        if(nums1[nElem1-1] > nums2[nElem2] && nElem2<size2){ // picked too much from nums1
            rsp = midsp-1;
        }
        else if(nums2[nElem2-1] > nums1[nElem1] && nElem1<size1){ // pick too less from nums1
            lsp = midsp;
        }
        else{
            break;
        }
    }


    // if reach here, we have 2 possibilities:
    // 1. all elements in nums1 are picked -> lsp = size1
    // 2. no elements in nums1 is picked -> rsp = 0
    // 3. found elements needed in nums1 and nums2

    if(nElem1 = size1){ //all elements in nums1 are picked
        if(halfSize-size1 == 0){ // no elements need from nums2
            if((size1+size2) % 2==1){
                return nums1[size1-1];
            }
            else{
//                double a = nums1[size1-1] + nums2[0];
//                a *= 0.5;
                return (nums1[size1-1] + nums2[0])*0.5;
            }
        }
        else{ // need some elements from nums2
            if((size1+size2) % 2==1){
                return nums2[halfSize-size1-1];
            }
            else{
                return (nums2[halfSize-size1-1] + nums2[halfSize-size1])*0.5;
            }
        }
    }

    if(nElem1==0){ // no elements in nums1 is picked, all should be from nums2
        if((size1+size2) % 2==1){
            return nums2[halfSize-1];
        }
        else{
            return (nums2[halfSize-1] + nums2[halfSize])*0.5;
        }
    }


    if( (size1+size2) % 2==1 ){
        return max(nums1[nElem1-1], nums2[nElem2-1]);
    }
    else{
        return (max(nums1[nElem1-1], nums2[nElem2-1])+min(nums1[nElem1], nums2[nElem2]))*0.5;
    }
}
