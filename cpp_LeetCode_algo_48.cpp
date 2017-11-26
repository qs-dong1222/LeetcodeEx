#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main(){
    vector<vector<int>> nums =
//    {
//      {1,2,3},
//      {4,5,6},
//      {7,8,9}
//    };
    {
      { 5, 1, 9,11},
      { 2, 4, 8,10},
      {13, 3, 6, 7},
      {15,14,12,16}
    };
    rotate(nums);

    for(auto eachRow : nums){
        for(auto each : eachRow){
            cout << each <<" ";
        }
        cout <<endl;
    }

    return 0;
}



void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty()) return;
    int dstR;
    int dstC;
    int currR;
    int currC;
    int preVal;
    int dstVal;

    unordered_set<int> visited;

    for(int r=0; r<matrix.size(); r++){
        for(int c=0; c<matrix[0].size(); c++){
            if(visited.count( ((r*5)<<3)+(c<<1)) ){
                continue;
            }
            currR = r;
            currC = c;
            preVal = matrix[currR][currC];
            while(true){
                dstR=currC;
                dstC=matrix.size()-1-currR;
                if(dstR==r && dstC==c){
                    matrix[dstR][dstC] = preVal;
                    visited.insert(((dstR*5)<<3)+(dstC<<1));
                    break;
                }
                dstVal = matrix[dstR][dstC];
                matrix[dstR][dstC] = preVal;
                visited.insert(((dstR*5)<<3)+(dstC<<1));
                preVal = dstVal;
                currR = dstR;
                currC = dstC;
            }
        }
    }
}
