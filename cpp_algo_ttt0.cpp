#include <iostream>
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int solution(vector<int> &A);

int main(){
    vector<int> nums = {500,1,-2,-1,2};
    cout << solution(nums) << endl;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<long long> sum(A.size(), 0);

    long long acc = 0;
    for(int i=0; i<A.size(); i++){
        acc += A[i];
        sum[i] = acc;
    }

    sum.insert(sum.begin(), 0);

//    for(auto each:sum){
//        cout << each <<" ";
//    }

    for(int i=1; i<(int)sum.size(); i++){
        long long leftSum = sum[i-1];
        long long rightSum = sum[sum.size()-1] - sum[i];

        if(rightSum == leftSum)
            return i-1;
    }

    return -1;
}
