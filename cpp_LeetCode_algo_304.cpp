#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>
#include <memory>


using namespace std;

inline int sumSqureWRTorigin(const vector<vector<int>>& matrix, int r, int c);
void NumMatrix(vector<vector<int>> matrix);
int sumRegion(int row1, int col1, int row2, int col2);

vector<vector<int>> matrix =
{
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
};


unordered_map<string, int> resMap;
vector<vector<int>> sum;

int main(){

    for(auto each:matrix){
        for(auto each1:each){
            cout << each1 << " ";
        }
        cout << endl;
    }

    NumMatrix(matrix);
    cout <<sumRegion(0,0,1,2) <<endl;
    return 0;
}


int sumRegion(int row1, int col1, int row2, int col2) {
    int result = sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    return result;
}

void NumMatrix(vector<vector<int>> matrix) {
    if(matrix.empty()){
        return;
    }

    int rSize = matrix.size();
    int cSize = matrix[0].size();
    sum.clear();
    sum = vector<vector<int>>(rSize+1, vector<int>(cSize+1,0));

    int r,c;
    for(r=0;r<rSize;r++){
        for(c=0;c<cSize;c++){
            sum[r+1][c+1] = sumSqureWRTorigin(matrix,r,c);
        }
    }
}

inline int sumSqureWRTorigin(const vector<vector<int>>& matrix, int r, int c){
    stringstream ss;
    ss << r << "," << c;
    string key = ss.str();
    if(resMap.find(key) != resMap.cend()){
        return resMap[key];
    }

    if(r<0 || c<0){
        return 0;
    }
    int res = sumSqureWRTorigin(matrix,r,c-1) + sumSqureWRTorigin(matrix,r-1,c) - sumSqureWRTorigin(matrix,r-1,c-1) + matrix[r][c];
    resMap[key] = res;
    return res;
}
