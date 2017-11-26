#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool IsCoordValid(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited);
bool DFS(vector<vector<char>>& board, string& word, int wordIdx, int currR, int currC, vector<vector<bool>>& visited);
bool exist(vector<vector<char>>& board, string word);

vector<vector<int>> direct =
{
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};


int main(){
    vector<vector<char>> board =
//    {
//      {'A','B','C','E'},
//      {'S','F','C','S'},
//      {'A','D','E','E'}
//    };

    {{'A'}};

    cout << exist(board, "A") << endl;


    return 0;
}


bool exist(vector<vector<char>>& board, string word) {
    if(word.empty()) return false;
    if(board.size()==1 && board[0].size()==1 && word.size()==1 && word[0]==board[0][0])
        return true;

    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for(int r=0;r<board.size();r++){
        for(int c=0;c<board[0].size();c++){
            if(DFS(board, word, 0, r,c, visited)){
                return true;
            }
        }
    }

    return false;
}



bool DFS(vector<vector<char>>& board, string& word, int wordIdx, int currR, int currC, vector<vector<bool>>& visited){
    if(wordIdx>=word.size()){
        return true;
    }

    for(auto dire:direct){
        int dr = dire[0];
        int dc = dire[1];
        if(IsCoordValid(board, currR+dr, currC+dc, visited) && board[currR+dr][currC+dc] == word[wordIdx]) {
            visited[currR+dr][currC+dc] = true;
            if(DFS(board, word, wordIdx+1, currR+dr, currC+dc, visited))
                return true;
            visited[currR+dr][currC+dc] = false;
        }
    }

    return false;
}



bool IsCoordValid(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited){
    int rSize = board.size();
    int cSize = board[0].size();

    if( (r>=0 && r<=rSize-1) && (c>=0 && c<=cSize-1) && !visited[r][c])
        return true;
    return false;
}


