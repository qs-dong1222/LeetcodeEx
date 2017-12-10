#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int findRequireHP(vector<vector<int>>& dungeon, int r, int c, int& pathSum);
int calculateMinimumHP(vector<vector<int>>& dungeon);

int main(){
    vector<vector<int>> dungeon =
//    {
//        {-2,-3,3},
//        {-5,-10,1},
//        {10,30,-5}
//    };
//    {
//        {1,-3,3},
//        {0,-2,0},
//        {-3,-3,-3}
//    };


    {
        {19,14,-25,-20,-36},
        {-46,-72,-74,25,-24},
        {-38,-57,-38,-73,-23},
        {-12,1,-70,44,-98}
    };

    cout << calculateMinimumHP(dungeon) << endl;

    return 0;
}

int calculateMinimumHP(vector<vector<int>>& dungeon){
    if(dungeon.empty()) return 0;

    int rows = dungeon.size();
    int cols = dungeon[0].size();

    vector<vector<int>> HP2end(rows+1, vector<int>(cols+1, INT_MAX));
    HP2end[rows][cols-1] = 1;
    HP2end[rows-1][cols] = 1;

    for(int r=HP2end.size()-2; r>=0; r--){
        for(int c=HP2end[0].size()-2; c>=0; c--){
            int nextHP = min(HP2end[r+1][c], HP2end[r][c+1]);
            if(dungeon[r][c] < 0){
                // current position need initial HP to continue
                HP2end[r][c] = nextHP + abs(dungeon[r][c]);
            }
            else{
                // current position has potion, just to be sure:
                // 1. alive at current position -> at least HP = 1.
                // 2. with current potion, we are able to reach next position -> current HP + potion = nextHP
                if(nextHP - dungeon[r][c] >= 0){
                    // potion provides part of nextHP, need some initial HP at least 1.
                    HP2end[r][c] = max(1, nextHP - dungeon[r][c]);
                }
                else{
                    // potion provides more than enough, just be sure we are alive to get this potion
                    HP2end[r][c] = 1;
                }
            }
        }
    }

    return HP2end[0][0];
}

