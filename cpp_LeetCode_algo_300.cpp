#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int,int> resMap;

int LISlength(vector<int>& nums, int endidx);


int main(){
    vector<int> v = {7,8,9,2,3};
    int idx;
    int maxLen = 0;
    for(idx=0;idx<(int)v.size();idx++){
        maxLen = max(LISlength(v,idx), maxLen);
//        cout << LISlength(v,idx) << endl;
    }


    cout << maxLen <<endl;

    return 0;
}


//returns length of LIS that ends with element idx th
int LISlength(vector<int>& nums, int endidx){
    if(resMap.find(endidx) != resMap.cend()){
        return resMap[endidx];
    }

    if(endidx==0){
        resMap[endidx] = 1;
        return 1;
    }

    int i;
    int tmax=1;
    for(i=endidx-1;i>=0;i--){
        if(nums[i] < nums[endidx]){
            tmax = max(LISlength(nums, i)+1, tmax);
        }
    }

    resMap[endidx] = tmax;
    return resMap[endidx];
}

