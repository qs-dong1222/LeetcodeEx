#include <iostream>
#include <vector>

using namespace std;

bool Check(vector<string>& chess, int row, int col);
void SolveChessByRow(vector<string>& chess, int row, vector<vector<string>>& ans);
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

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if(n==0) return ans;

    vector<string> chess(n, string(n, '.'));
    SolveChessByRow(chess, 0, ans);

    return ans;
}



void SolveChessByRow(vector<string>& chess, int row, vector<vector<string>>& ans){
    if(chess.empty()) return;

    if(row == (int)chess.size()){
        ans.push_back(chess);
        return;
    }

    int c;
    for(c=0; c<(int)chess[0].size(); c++){
        if( Check(chess, row, c) ){
            chess[row][c] = 'Q';
            SolveChessByRow(chess, row+1, ans);
            chess[row][c] = '.';
        }
    }

    return;
}

bool Check(vector<string>& chess, int row, int col){
    int r,c;
    //horizontally
    for(c=0; c<(int)chess[0].size(); c++){
        if(chess[row][c] == 'Q') return false;
    }

    //vertically
    for(r=0; r<(int)chess.size(); r++){
        if(chess[r][col] == 'Q') return false;
    }

    //topleft
    for(r=row-1, c=col-1; r>=0&&c>=0; r--,c--){
        if(chess[r][c] == 'Q') return false;
    }

    //topright
    for(r=row-1, c=col+1; r>=0&&c<(int)chess[0].size(); r--,c++){
        if(chess[r][c] == 'Q') return false;
    }

    //botright
    for(r=row+1, c=col+1; r<(int)chess.size()&&c<(int)chess[0].size(); r++,c++){
        if(chess[r][c] == 'Q') return false;
    }

    //botleft
    for(r=row+1, c=col-1; r<(int)chess.size()&&c>=0; r++,c--){
        if(chess[r][c] == 'Q') return false;
    }

    return true;
}
