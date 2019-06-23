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
    /*
    {
        {'A'}
    };
    cout << exist(board, "AB") << endl;
    */

    /*
    {
        {'A', 'A'}
    };
    cout << exist(board, "A") << endl;
    */


//    {
//      {'A','B','C','E'},
//      {'S','F','C','S'},
//      {'A','D','E','E'}
//    };
//    cout << exist(board, "ABCCED") << endl;

    {
      {'C','A','A'},
      {'A','A','A'},
      {'B','C','D'}
    };
    cout << exist(board, "AAB") << endl;



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







/*
    这个BFS的方法没有AC, 虽然大致思路构建了, 但有很多地方不完善. 需要比DFS考虑更多的边界条件.
    比如:
        第一轮的两个元素是相互独立的, 不用互为visited 等等.
*/
bool IsCoordValid(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited){
    int rSize = board.size();
    int cSize = board[0].size();

    if( (r>=0 && r<=rSize-1) && (c>=0 && c<=cSize-1) && !visited[r][c])
        return true;
    return false;
}


bool exist(vector<vector<char>>& board, string word) {
    int wsize = word.size();
    if(wsize == 0) return false;
//    if(board.size()==1 && board[0].size()==1 && word.size()==1 && word[0]==board[0][0])
//        return true;

    queue<vector<int>> p;
    queue<vector<int>> q; //vector[0] = row
                          //vector[1] = col
                          //vector[2] = letter

    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    // find initial letter
    for(int r=0; r<(int)board.size(); r++){
        for(int c=0; c<(int)board[0].size(); c++){
            if(board[r][c] == word[0]){
                vector<int> letter_info = {r, c, board[r][c]};
                p.push(letter_info);
            }
        }
    }

    int target_char_idx = 0; // index of char that should be currently compared
    // BFS
    for(int j=(int)p.size()-1; j>=0; j--){
        q.push(p.front());
        p.pop();

        while(!q.empty()){
            target_char_idx++;

            // visit all element pushed from last layer
            for(int i=(int)q.size()-1; i>=0; i--){ // size will change when push new element, so
                                                   // it has to be style of i-- here
                // fetch and pop out the front element
                vector<int> letter_info(q.front());
                q.pop();
                visited[letter_info[0]][letter_info[1]] = true;
                //cout << "board["<<letter_info[0]<<"]"<<"["<<letter_info[1]<<"]="<<(char)letter_info[2]<<endl;

                // search new candidates for the front element
                for(auto dire:direct){
                    int next_r = letter_info[0] + dire[0];
                    int next_c = letter_info[1] + dire[1];
                    if(IsCoordValid(board, next_r, next_c, visited)
                       && board[next_r][next_c] == word[target_char_idx]){ // we should append this letter
                        if(target_char_idx >= wsize-1){ // already finished
                            return true;
                        } else { // we should add this letter to queue for next round
                            vector<int> new_letter_info = {next_r, next_c, board[next_r][next_c]};
                            q.push(new_letter_info);
                        }
                    }
                }
            }
        }
    }

    if(target_char_idx > wsize-1) return true; // only one same char in board and word

    return false;
}
