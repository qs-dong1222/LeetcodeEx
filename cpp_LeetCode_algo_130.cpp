#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <deque>

using namespace std;


vector<vector<int>> offset =
{
    {-1,0},
    {0,-1},
    {0,1},
    {1,0}
};


struct COORD{
    int r;
    int c;
    bool operator==(const COORD &coord) const {
        if(this->r == coord.r && this->c == coord.c){
            return true;
        }
        return false;
    }
};
//struct myhash {
//public:
//   size_t operator()(const COORD &coord) const {
//        return ((coord.r*13)<<5)+coord.c;
//    }
//};

void unflipflood(vector<vector<char>>& board, int r, int c);
bool IsValid(vector<vector<char>>& board, int r, int c);
void solve(vector<vector<char>>& board);

int main(){
    vector<vector<char>> board =
    {
        {'X','X','X','O','O','X'},
        {'X','X','O','O','O','X'},
        {'X','X','X','O','O','O'},
        {'X','X','X','X','X','X'},
        {'X','O','O','X','X','X'},
        {'X','O','O','X','X','X'},
        {'X','X','X','X','X','X'}
    };

    solve(board);

    for(auto eachR : board){
        for(auto each : eachR){
            cout << each << "   ";
        }
        cout << endl;
    }

    return 0;
}


void solve(vector<vector<char>>& board){
    if(board.empty()) return;

    // 0th row, last row
    for(int c=0;c<(int)board[0].size();c++){
        if(board[0][c] == 'O')
            unflipflood(board, 0, c);
        if(board[board.size()-1][c] == 'O')
            unflipflood(board, board.size()-1, c);
    }

    // 0th col, last col
    for(int r=0;r<(int)board.size();r++){
        if(board[r][0] == 'O')
            unflipflood(board, r, 0);
        if(board[r][board[0].size()-1] == 'O')
            unflipflood(board, r, board[0].size()-1);
    }

    for(int r=0;r<(int)board.size();r++){
        for(int c=0;c<(int)board[0].size();c++){
            if(board[r][c] != 'C')
                board[r][c] = 'X';
            else
                board[r][c] = 'O';
        }
    }
}



void unflipflood(vector<vector<char>>& board, int r, int c){
    queue<COORD> q;
     COORD startCoord = {r, c};
    q.push(startCoord);
    COORD curr;
    while(!q.empty()){

        for(int i=q.size(); i>0; i--){
            curr = q.front(); q.pop();
            board[curr.r][curr.c] = 'C';

            for(auto eachOffset : offset){
                int offsetR = eachOffset[0];
                int offsetC = eachOffset[1];
                COORD newCoord = {curr.r+offsetR, curr.c+offsetC};
                if(IsValid(board, newCoord.r, newCoord.c)){
                    q.push(newCoord);
                }
            }
        }
    }
}




bool IsValid(vector<vector<char>>& board, int r, int c){
    if(r<0 || r>=(int)board.size() || c>(int)board[0].size() || c<0){
        return false;
    }
    if(board[r][c]=='X' || board[r][c]=='C'){
        return false;
    }
    return true;
}







/*
BFS flood filling solution, time limit exceeded
*/
//bool IsValid(vector<vector<char>>& board, vector<vector<bool>>& unfilpable, int r, int c);
//void unflipflood(vector<vector<char>>& board, vector<vector<bool>>& unfilpable, int r, int c);
//bool IsAtEdge(vector<vector<char>>& board, const int& r, const int& c);
//void solve(vector<vector<char>>& board);
//
//int main(){
//    vector<vector<char>> board =
//    {
//        {'X','X','X','O','O','X'},
//        {'X','X','O','O','O','X'},
//        {'X','X','X','O','O','O'},
//        {'X','X','X','X','X','X'},
//        {'X','O','O','X','X','X'},
//        {'X','O','O','X','X','X'},
//        {'X','X','X','X','X','X'}
//    };
//
//    solve(board);
//
//    for(auto eachR : board){
//        for(auto each : eachR){
//            cout << each << "   ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
//
//
//void solve(vector<vector<char>>& board) {
//    vector<vector<bool>> unflipable(board.size(), vector<bool>(board[0].size(), false));
//    for(int r=0;r<(int)board.size();r++){
//        for(int c=0;c<(int)board[0].size();c++){
//            if(!unflipable[r][c]){
//                if(board[r][c] == 'X'){
//                    // this is 'X'
//                    unflipable[r][c] = true;
//                }
//                else if(IsAtEdge(board, r, c)){
//                    // this is 'O' at edge
//                    unflipflood(board, unflipable, r, c);
//                }
//            }
//        }
//    }
//
//    for(int r=0;r<(int)board.size();r++){
//        for(int c=0;c<(int)board[0].size();c++){
//            if(!unflipable[r][c]){
//                board[r][c] = 'X';
//            }
//        }
//    }
//}
//
//
//void unflipflood(vector<vector<char>>& board, vector<vector<bool>>& unfilpable, int r, int c){
//    queue<COORD> q;
//    unordered_set<COORD, myhash> visited;
//
//    COORD startCoord = {r, c};
//    q.push(startCoord);
//    COORD curr;
//    while(!q.empty()){
//
//        for(int i=q.size(); i>0; i--){
//            curr = q.front(); q.pop();
//            visited.insert(curr);
//            unfilpable[curr.r][curr.c] = true;
//
//            for(auto eachOffset : offset){
//                int offsetR = eachOffset[0];
//                int offsetC = eachOffset[1];
//                COORD newCoord = {curr.r+offsetR, curr.c+offsetC};
//                if(IsValid(board, unfilpable, newCoord.r, newCoord.c)){
//                    q.push(newCoord);
//                }
//            }
//        }
//    }
//}
//
//
//
//bool IsValid(vector<vector<char>>& board, vector<vector<bool>>& unfilpable, int r, int c){
//    if(r<0 || r>=(int)unfilpable.size() || c>(int)unfilpable[0].size() || c<0){
//        return false;
//    }
//    if(unfilpable[r][c] || board[r][c]=='X'){
//        return false;
//    }
//    return true;
//}



//// see if at board boundary
//bool IsAtEdge(vector<vector<char>>& board, const int& r, const int& c){
//    if(r==0 || r==(int)board.size()-1 || c==(int)board[0].size()-1 || c==0){
//        return true;
//    }
//    return false;
//}
