#include <iostream>
#include <vector>

using namespace std;
bool biSearch(vector<int>& v, int target);
bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(){
    vector<vector<int>> matrix =
//    {
//      {1,   3,  5,  7},
//      {10, 11, 16, 20},
//      {23, 30, 34, 50}
//    };
    {
        {1,3,5}
    };

    cout << searchMatrix(matrix, 1) << endl;

    return 0;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].size()==0) return false;

    for(auto eachRow : matrix){
        if(eachRow[eachRow.size()-1] > target)
            return biSearch(eachRow, target);
        else if(eachRow[eachRow.size()-1] == target)
            return true;
    }

    return false;
}


bool biSearch(vector<int>& v, int target){
    int lidx=0, ridx=v.size()-1;
    int mid;
    while(lidx<=ridx){
        mid = lidx + (ridx-lidx)/2;
        if(v[mid] == target)
            return true;
        else if(v[mid] > target)
            ridx = mid-1;
        else
            lidx = mid+1;
    }

    return false;
}

