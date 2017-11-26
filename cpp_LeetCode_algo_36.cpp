#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetBoxIndex(int r, int c);
bool isValidSudoku(vector<vector<char>>& board);

int main(){

    return 0;
}


bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rowNumsExist(10, vector<int>(10,false));
    vector<vector<int>> colNumsExist(10, vector<int>(10,false));
    vector<vector<int>> boxNumsExist(10, vector<int>(10,false));

    int numIdx;
    for(int r=0; r<board.size(); r++){
        for(int c=0; c<board[0].size(); c++){
            if(board[r][c] != '.'){
                numIdx = board[r][c] - '0';
                if( rowNumsExist[r][numIdx] ) return false;
                rowNumsExist[r][numIdx] = true;
                if( colNumsExist[c][numIdx] ) return false;
                colNumsExist[c][numIdx] = true;
                if( boxNumsExist[GetBoxIndex(r,c)][numIdx] ) return false;
                boxNumsExist[GetBoxIndex(r,c)][numIdx] = true;
            }
        }
    }

    return true;
}



int GetBoxIndex(int r, int c){
    return (r/3)*3 + c/3;
}
