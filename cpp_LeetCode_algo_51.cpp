#include <iostream>
#include <vector>

using namespace std;

//bool Check(vector<string>& chess, int row, int col);
//void SolveChessByRow(vector<string>& chess, int row, vector<vector<string>>& ans);


bool IsValid(vector<string>& chess, int r, int c);
void Fill(vector<string>& chess, int r, vector<vector<string>>& ans);
vector<vector<string>> solveNQueens(int n);


int main(){
    vector<vector<string>> ans = solveNQueens(4);
    for(auto eachChess:ans){
        for(auto eachLine:eachChess){
            cout << eachLine << endl;
        }
        cout << endl;
    }


    return 0;
}



/*
实际上这种dfs的问题一般有两种角度.
1. 试着去填一个结果, 再检测这个尝试的正确性, 并根据正确性进行回溯/下一步安排
2. 先检测一个尝试的可行性, 可行了就做, 并根据做了的结果进行回溯/下一步安排
*/



/*
solution 1: check validation before fill
*/
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if(n==0) return ans;

    vector<string> chess(n, string(n, '.'));
    Fill(chess, 0, ans);
    return ans;
}

void Fill(vector<string>& chess, int r, vector<vector<string>>& ans){
    if(r>=(int)chess.size()){
        ans.push_back(chess);
        return;
    }

    for(int c=0; c<(int)chess[0].size(); c++){
        if(IsValid(chess, r, c)){
            chess[r][c] = 'Q';
            Fill(chess, r+1, ans);
            chess[r][c] = '.';
        }
    }

}

bool IsValid(vector<string>& chess, int r, int c){
    if(r<0 || r>=(int)chess.size() || c<0 || c>=(int)chess[0].size() || chess[r][c]=='Q'){
        return false;
    }

    // row check
    for(int col=0; col<(int)chess[0].size(); col++){
        if(chess[r][col] == 'Q') return false;
    }

    // col check
    for(int row=0; row<(int)chess.size(); row++){
        if(chess[row][c] == 'Q') return false;
    }

    // top left check
    for(int row=r-1,col=c-1; row>=0&&col>=0; row--,col--){
        if(chess[row][col] == 'Q') return false;
    }

    // right bot check
    for(int row=r+1,col=c+1; row<(int)chess.size()&&col<(int)chess[0].size(); row++,col++){
        if(chess[row][col] == 'Q') return false;
    }

    // right top check
    for(int row=r-1,col=c+1; row>=0&&col<chess[0].size(); row--, col++){
        if(chess[row][col] == 'Q') return false;
    }

    // left bot check
    for(int row=r+1,col=c-1; row<(int)chess.size()&&col>=0; row++, col--){
        if(chess[row][col] == 'Q') return false;
    }

    return true;
}
