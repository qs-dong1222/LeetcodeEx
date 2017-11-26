#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> resMap;

bool IsValid(vector<vector<int>>& obstacleGrid, int nextR, int nextC);
//void DFS(vector<vector<int>>& obstacleGrid, int nextR, int nextC, int& ans);
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
int FindNbrOfPathAtCoord(vector<vector<int>>& obstacleGrid, int r, int c);

int main(){
    vector<vector<int>> obstacleGrid =
    {
      {0,0,0},
      {0,1,0},
      {0,0,0}
    };

    int ans = uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;

    return 0;
}




/*
Valid solution: dynamic programming
*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty()) return 0;
    return FindNbrOfPathAtCoord(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1);
}

int FindNbrOfPathAtCoord(vector<vector<int>>& obstacleGrid, int r, int c){
    string key;
    key.push_back(r+'0');
    key.push_back(c+'0');
    if(resMap.count(key)){
        return resMap[key];
    }

    if(r==0 && c==0){
        if(obstacleGrid[r][c] == 0)
            return 1;
        else
            return 0;
    }

    if(r==0 && c!=0){
        if(IsValid(obstacleGrid, r, c-1))
            resMap[key] = FindNbrOfPathAtCoord(obstacleGrid, r, c-1);
        else
            resMap[key] = 0;
        return resMap[key];
    }

    if(r!=0 && c==0){
        if(IsValid(obstacleGrid, r-1, c))
            resMap[key] = FindNbrOfPathAtCoord(obstacleGrid, r-1, c);
        else
            resMap[key] = 0;
        return resMap[key];
    }

    if(IsValid(obstacleGrid, r-1, c))
        resMap[key] += FindNbrOfPathAtCoord(obstacleGrid, r-1,c);
    if(IsValid(obstacleGrid, r, c-1))
        resMap[key] += FindNbrOfPathAtCoord(obstacleGrid, r,c-1);
    return resMap[key];
}








/*
DFS solution, time exceed
*/
//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//    if(obstacleGrid.empty()) return 0;
//
//    int ans = 0;
//    DFS(obstacleGrid, 0,0, ans);
//    return ans;
//}
//void DFS(vector<vector<int>>& obstacleGrid, int nextR, int nextC, int& ans){
//    if( !IsValid(obstacleGrid, nextR, nextC) ) return;
//    if(nextR == obstacleGrid.size()-1 && nextC == obstacleGrid[0].size()-1){
//        ans++;
//        return;
//    }
//
//    if(IsValid(obstacleGrid, nextR, nextC+1))
//        DFS(obstacleGrid, nextR, nextC+1, ans);
//    if(IsValid(obstacleGrid, nextR+1, nextC))
//        DFS(obstacleGrid, nextR+1, nextC, ans);
//}




bool IsValid(vector<vector<int>>& obstacleGrid, int nextR, int nextC){
    if(nextR>=obstacleGrid.size() || nextC>=obstacleGrid[0].size())
        return false;
    if(obstacleGrid[nextR][nextC] != 0)
        return false;

    return true;
}
