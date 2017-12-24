#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool IsValid(vector<vector<int>>& board, int r, int c);
void fillBoard(vector<vector<int>>& board, int r, int c, unordered_set<int>& used);
void printBoard(vector<vector<int>>& board);


int main(){

    vector<vector<int>> board =
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };


    unordered_set<int> used;

    fillBoard(board, 0, 0, used);


    return 0;
}




void fillBoard(vector<vector<int>>& board, int r, int c, unordered_set<int>& used){
    if(r >= (int)board.size()){
        printBoard(board);
        return;
    }

    int nextR = r + ((c+1) / board.size());
    int nextC = (c+1) % board.size();

    for(int num=1;num<=(int)board.size()*(int)board[0].size();num++){
        if(used.count(num)) continue;
        used.insert(num);
        board[r][c] = num;
        if(IsValid(board, r, c)){ // if this fill is valid
            fillBoard(board, nextR, nextC, used);
            board[r][c] = 0;
            used.erase(num);
        }
        else{ // if this fill is not valid
            board[r][c] = 0;
            used.erase(num);
        }

    }
}


void printBoard(vector<vector<int>>& board){
    for(auto eachRow:board){
        for(auto each:eachRow){
            cout << each<< " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool IsValid(vector<vector<int>>& board, int r, int c){
    int result = (1+board.size()*board[0].size())/2 + 1 + board.size()*board[0].size();
    // row verification
    int sum = 0;
    for(int i=0;i<=c;i++){
        sum += board[r][i];
    }
    if(c == (int)board[0].size()-1){
        if(sum != result)
            return false;
    }
    else{
        if(sum >= result)
            return false;
    }


    // col verification
    sum = 0;
    for(int i=0;i<=r;i++){
        sum += board[i][c];
    }
    if(r == (int)board.size()-1){
        if(sum != result)
            return false;
    }
    else{
        if(sum >= result)
            return false;
    }


    // dig verification
    sum = 0;
    if(r==c){
        for(int i=0, j=0; i<=r, j<=c; i++,j++){
            sum += board[i][j];
        }
        if(r==(int)board.size()-1){
            // bot right box
            if(sum != result)
                return false;
        }
        else{
            if(sum >= result)
                return false;
        }
    }


//    00 01 02
//    10 11 12
//    20 21 22

    // backdig verification
    sum = 0;
    if(r+c == (int)board.size()-1){
        for(int i=0, j=(int)board[0].size()-1; i<=r, j>=0; i++,j--){
            sum += board[i][j];
        }
        if(r==(int)board.size()-1){
            // bot left box
            if(sum != result)
                return false;
        }
        else{
            if(sum >= result)
                return false;
        }
    }

    return true;

}
