#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//int DFS(string& targetS, string& srcS, int tarIdx, int srcIdx, int& step);

unordered_map<string, int> resMap;
void setZeroes(vector<vector<int>>& matrix);

int main(){

    vector<vector<int>> mat =
//    {
//        {0,1,1,1,1,1,1,1},
//        {1,1,1,1,1,1,1,1},
//        {1,1,0,1,1,1,1,1},
//        {1,1,1,1,1,1,1,1},
//        {1,1,1,1,1,0,1,1},
//        {1,1,1,1,1,1,1,0}
//    };
    {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,1,0},
        {1,1,1,1}
    };

    setZeroes(mat);

    for(auto eachRow : mat){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}













// 第x次做题时的解法:
// 思路较为简单, 清零时, 要避免的是在一个位置上重复进行清零操作
// 比如 (1,3)和(1,5) 这两个点, 他们都会对 1st 这一行进行清零, 那么我们就会有重复操作, 而实际上我们只做一次操作就行了
// 避免的方法就是 先从全局角度上去记录每个 行,列 是否需要清零.
// 最后再全局一次性做一遍清零操作.
void setZeroes(vector<vector<int>>& matrix) {
    vector<bool> rowToBeZero(matrix.size(), false);
    vector<bool> colToBeZero(matrix[0].size(), false);

    for(int r=0; r<(int)matrix.size(); r++){
        for(int c=0; c<(int)matrix[0].size(); c++){
            if(matrix[r][c]==0){
                rowToBeZero[r] = true;
                colToBeZero[c] = true;
            }
        }
    }


    for(int r=0; r<(int)rowToBeZero.size(); r++){
        if(rowToBeZero[r]){
            for(int c=0; c<(int)matrix[0].size(); c++){
                matrix[r][c] = 0;
            }
        }
    }


    for(int c=0; c<(int)colToBeZero.size(); c++){
        if(colToBeZero[c]){
            for(int r=0; r<(int)matrix.size(); r++){
                matrix[r][c] = 0;
            }
        }
    }

}



//void setZeroes(vector<vector<int>>& matrix) {
//    int rowSize = matrix.size();
//    int colSize = matrix[0].size();
//
//    int r,c;
//    bool firstColIsZero = false;
//    bool firstRowIsZero = false;
//
//    for(c=0;c<colSize;c++)
//        if(matrix[0][c]==0)
//            firstRowIsZero = true;
//
//    for(r=0;r<rowSize;r++){
//        if(matrix[r][0]==0)
//            firstColIsZero = true;
//        for(c=0;c<colSize;c++){
//            if(matrix[r][c]==0){
//                matrix[r][0] = 0;
//                matrix[0][c] = 0;
//            }
//        }
//    }
//
//    for(c=1;c<colSize;c++){
//        if(matrix[0][c] == 0){
//            for(r=1;r<rowSize;r++)
//                matrix[r][c] = 0;
//        }
//    }
//
//    for(r=1;r<rowSize;r++){
//        if(matrix[r][0] == 0){
//            for(c=1;c<colSize;c++)
//                matrix[r][c] = 0;
//        }
//    }
//
//    if(firstColIsZero){
//        for(r=0;r<rowSize;r++)
//            matrix[r][0] = 0;
//    }
//    if(firstRowIsZero){
//        for(c=0;c<colSize;c++)
//            matrix[0][c] = 0;
//    }
//}

