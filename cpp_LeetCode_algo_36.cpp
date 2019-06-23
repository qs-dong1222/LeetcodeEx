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
    int box_has_cols = 3;
    int box_has_rows = 3;
    int box_row_idx = r / box_has_rows;
    int box_col_idx = c / box_has_cols;
    int n_boxes_per_row = 3;
    return (box_col_idx + box_row_idx * n_boxes_per_row);
}

