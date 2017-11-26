#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> resMap;
int FindMinValAlongPathAtCoord(vector<vector<int>>& grid, int r, int c);

int main(){
    vector<vector<int>> grid =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << FindMinValAlongPathAtCoord(grid, grid.size()-1, grid[0].size()-1) << endl;


    return 0;
}



int FindMinValAlongPathAtCoord(vector<vector<int>>& grid, int r, int c){
    if(grid.empty()) return 0;
    string key;
    key.push_back(r+'0');
    key.push_back(c+'0');

    if(resMap.count(key)) return resMap[key];

    if(r==0 && c==0){
        resMap[key] = grid[r][c];
        return resMap[key];
    }

    if(r==0 && c!=0){
        resMap[key] = grid[r][c] + FindMinValAlongPathAtCoord(grid, r, c-1);
        return resMap[key];
    }

    if(c==0 && r!=0){
        resMap[key] = grid[r][c] + FindMinValAlongPathAtCoord(grid, r-1, c);
        return resMap[key];
    }

    resMap[key] = grid[r][c] + min(FindMinValAlongPathAtCoord(grid, r-1, c), FindMinValAlongPathAtCoord(grid, r, c-1));
    return resMap[key];
}


