#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board);
int boxidx(int r, int c);

int main(){

    return 0;
}


bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rowExist(board.size(), vector<bool>(10, false));
    vector<vector<bool>> colExist(board[0].size(), vector<bool>(10, false));
    vector<vector<bool>> boxExist(board.size(), vector<bool>(10, false));

    for(int r=0;r<board.size();r++){
        for(int c=0;c<board[0].size();c++){
            if(board[r][c]!='.'){
                int digit = board[r][c]-'0';
                if(rowExist[r][digit] || colExist[c][digit] || boxExist[boxidx(r,c)][digit]){
                    return false;
                }
                else{
                    rowExist[r][digit] = true;
                    colExist[c][digit] = true;
                    boxExist[boxidx(r,c)][digit] = true;
                }
            }
        }
    }

    return true;
}


int boxidx(int r, int c){
    return (c/3 + (r/3)*3);
}

