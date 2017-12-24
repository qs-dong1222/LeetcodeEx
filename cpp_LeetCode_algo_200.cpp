#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
void SinkIsland(vector<vector<char>>& grid, int r, int c);
int numIslands(vector<vector<char>>& grid);

int main(){
    vector<vector<char>> grid =
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << numIslands(grid) <<endl;

    return 0;
}


int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    if(grid.empty()) return ans;

    for(int r=0;r<(int)grid.size();r++){
        for(int c=0;c<(int)grid[0].size();c++){
            if(grid[r][c]=='1'){ //found an island
                ans++; // number of island + 1
                SinkIsland(grid, r, c);
            }
        }
    }

    return ans;
}


void SinkIsland(vector<vector<char>>& grid, int r, int c){
    if(r<0 || r>=(int)grid.size() || c<0 || c>=(int)grid[0].size() || grid[r][c]=='0'){
        return;
    }

    grid[r][c] = '0';
    SinkIsland(grid, r-1, c);
    SinkIsland(grid, r+1, c);
    SinkIsland(grid, r, c-1);
    SinkIsland(grid, r, c+1);
}
