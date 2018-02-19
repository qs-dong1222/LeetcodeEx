#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> resMap;
int FindMinValAlongPathAtCoord(vector<vector<int>>& grid, int r, int c);
int minPathSum(vector<vector<int>>& grid);


int main(){
    vector<vector<int>> grid =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    //cout << FindMinValAlongPathAtCoord(grid, grid.size()-1, grid[0].size()-1) << endl;

    cout << minPathSum(grid) << endl;

    return 0;
}





/*
solution 1 : bottom up dp
*/
int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;

    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    dp[0][0] = grid[0][0];

    // init 0th row
    for(int c=1; c<(int)dp[0].size(); c++){
        dp[0][c] = grid[0][c] + dp[0][c-1];
    }
    // init 0th col
    for(int r=1; r<(int)dp.size(); r++){
        dp[r][0] = grid[r][0] + dp[r-1][0];
    }

    for(int r=1; r<(int)dp.size(); r++){
        for(int c=1; c<(int)dp[0].size(); c++){
            dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
        }
    }

    return dp[grid.size()-1][grid[0].size()-1];
}











/*
solution 2 : memorization dp
*/
//int FindMinValAlongPathAtCoord(vector<vector<int>>& grid, int r, int c){
//    if(grid.empty()) return 0;
//    string key;
//    key.push_back(r+'0');
//    key.push_back(c+'0');
//
//    if(resMap.count(key)) return resMap[key];
//
//    if(r==0 && c==0){
//        resMap[key] = grid[r][c];
//        return resMap[key];
//    }
//
//    if(r==0 && c!=0){
//        resMap[key] = grid[r][c] + FindMinValAlongPathAtCoord(grid, r, c-1);
//        return resMap[key];
//    }
//
//    if(c==0 && r!=0){
//        resMap[key] = grid[r][c] + FindMinValAlongPathAtCoord(grid, r-1, c);
//        return resMap[key];
//    }
//
//    resMap[key] = grid[r][c] + min(FindMinValAlongPathAtCoord(grid, r-1, c), FindMinValAlongPathAtCoord(grid, r, c-1));
//    return resMap[key];
//}


