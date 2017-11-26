#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>


using namespace std;


void UpdateMaxes(int& ori_mmax, int& ori_max, int new_mmax, int new_max){
    ori_mmax = new_mmax;
    ori_max = new_max;
}

int FindNbrOfLIS(vector<int>& v, int n);

template<typename dType>
int FindLISlength(vector<dType>& v, int n);
unordered_map<int, int> resMap;

int main(){
    vector<int> v = {2,2,2,2,2};
//    vector<int> v = {1,3,5,4,7};

    cout << FindNbrOfLIS(v, v.size()) <<endl;

    return 0;
}



/*
Find number of subsequence with length of LIS
*/
int FindNbrOfLIS(vector<int>& v, int n){
    int maxLen = FindLISlength(v,n);
    maxLen = maxLen==1? 2:maxLen;
    int i, cnt=0;
    for(i=0;i<n;i++){
        if(FindLISlength(v,i) == maxLen-1 && v[i-1]<=v[n-1]){
            cnt++;
        }
    }

    if(v[n-2]==v[n-1]){
        return cnt+1;
    }
    return cnt;
}












/////////////////////
//  wrong below !!! cannot solve 7,8,9,2,3
/////////////////////
/*
Find longest increasing subsequence length for first n numbers in vector
*/
template<typename dType>
int FindLISlength(vector<dType>& v, int n){
    // memorization
    if(resMap.find(n) != resMap.cend()){
        return resMap[n];
    }

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    if(v[n-1]<=v[n-2]){
        resMap[n] = FindLISlength(v, n-1);
        return resMap[n];
    }
    else{
        resMap[n] = FindLISlength(v, n-1)+1;
        return resMap[n];
    }
}
