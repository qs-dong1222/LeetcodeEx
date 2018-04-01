#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool IsCoordValid(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited);
bool DFS(vector<vector<char>>& board, string& word, int wordIdx, int currR, int currC, vector<vector<bool>>& visited);
bool exist(vector<vector<char>>& board, string word);
bool dfsearch(vector<vector<char>>& board, int r, int c, string& word, int ch_idx, vector<vector<bool>>& visited);



vector<vector<int>> direct =
{
    {-1,0}, // up
    {1,0}, // down
    {0,-1}, // left
    {0,1}  // right
};


int main(){
    vector<vector<char>> board =
//    {
//      {'A','B','C','E'},
//      {'S','F','C','S'},
//      {'A','D','E','E'}
//    };
//    cout << exist(board, "ABCESEECFSA") << endl;


    {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    cout << exist(board, "ABCESEEEFS") << endl;


//    {{'A'}};
//    cout << exist(board, "A") << endl;
    return 0;
}





bool exist(vector<vector<char>>& board, string word) {
    if(word.empty()) return true;
    if(board.empty()) return false;
//    if(board.size()==1 && board[0].size()==1 && word.size()==1 && word[0]==board[0][0]) return true;

    char beginword = word[0];

    for(int r=0; r<(int)board.size(); r++){
        for(int c=0; c<(int)board[0].size(); c++){
            if(board[r][c] == beginword){
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if(dfsearch(board, r, c, word, 0, visited)){
                    return true;
                }
            }
        }
    }

    return false;
}


bool dfsearch(vector<vector<char>>& board, int r, int c, string& word, int ch_idx, vector<vector<bool>>& visited){
    if(ch_idx>=(int)word.size()){
        return true;
    }

    if(board[r][c] == word[ch_idx]){
        if(ch_idx == (int)word.size()-1) return true;
        visited[r][c] = true;
        for(auto eachDirect:direct){
            int next_r = r + eachDirect[0];
            int next_c = c + eachDirect[1];
            if(next_r < (int)board.size()
               && next_r >= 0
               && next_c < (int)board[0].size()
               && next_c >= 0
               && !visited[next_r][next_c]){
                if(dfsearch(board, next_r, next_c, word, ch_idx+1, visited)){
                    return true;
                }
            }
        }
    }
    visited[r][c] = false;
    return false;
}




























//bool exist(vector<vector<char>>& board, string word) {
//    if(word.empty()) return false;
//    if(board.size()==1 && board[0].size()==1 && word.size()==1 && word[0]==board[0][0])
//        return true;
//
//    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
//
//    for(int r=0;r<board.size();r++){
//        for(int c=0;c<board[0].size();c++){
//            if(DFS(board, word, 0, r,c, visited)){
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//
//
//
//bool DFS(vector<vector<char>>& board, string& word, int wordIdx, int currR, int currC, vector<vector<bool>>& visited){
//    if(wordIdx>=word.size()){
//        return true;
//    }
//
//    for(auto dire:direct){
//        int dr = dire[0];
//        int dc = dire[1];
//        if(IsCoordValid(board, currR+dr, currC+dc, visited) && board[currR+dr][currC+dc] == word[wordIdx]) {
//            visited[currR+dr][currC+dc] = true;
//            if(DFS(board, word, wordIdx+1, currR+dr, currC+dc, visited))
//                return true;
//            visited[currR+dr][currC+dc] = false;
//        }
//    }
//
//    return false;
//}
//
//
//
//bool IsCoordValid(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited){
//    int rSize = board.size();
//    int cSize = board[0].size();
//
//    if( (r>=0 && r<=rSize-1) && (c>=0 && c<=cSize-1) && !visited[r][c])
//        return true;
//    return false;
//}


