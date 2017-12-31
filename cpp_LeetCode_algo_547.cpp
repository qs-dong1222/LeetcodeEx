#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int findCircleNum(vector<vector<int>>& M);
void SinkFriends(vector<vector<int>>& M, int r, int c);
void ExpandCircle(const vector<vector<int>>& M, int p1, vector<bool>& visited);
void print(vector<vector<int>>& M);

int main(){

    vector<vector<int>> M =
    {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

//    {
//        {1,0,0,1},
//        {0,1,1,0},
//        {0,1,1,1},
//        {1,0,1,1}
//    };

    cout << findCircleNum(M) << endl;

    return 0;
}









/*
solution 1 : 断绝朋友圈中的所有关系.

这种方法时间复杂度略高，但不占空间
*/
//int findCircleNum(vector<vector<int>>& M) {
//    int ans = 0;
//    if(M.empty()) return ans;
//
//    for(int r=0;r<(int)M.size();r++){
//        for(int c=0;c<(int)M[0].size();c++){
//            if(M[r][c] != 0){
//                ans++;
//                SinkFriends(M, r, c);
//            }
//        }
//    }
//
//    return ans;
//}
//
//void SinkFriends(vector<vector<int>>& M, int p1, int p2){
//    // p1不再认识p2
//    M[p1][p2] = 0;
//    // p2也不再认识p1
//    M[p2][p1] = 0;
//
//    for(int p=0;p<(int)M[0].size();p++){
//        if(M[p2][p] != 0){
//            //所有p2已经认识的这个人断绝关系
//            SinkFriends(M, p2, p);
//            //这个认识p2的人也断绝关系
//            M[p][p2] = 0;
//        }
//    }
//}



/*
solution 2 : 每当见到一个"之前毫无记录/之前完全没见过"的新人时，构建其朋友圈。
以此类推，直到再没有"之前毫无记录/之前完全没见过"的新人为止.

这种方法有m(n)的空间复杂度，但时间复杂度略低
*/
int findCircleNum(vector<vector<int>>& M) {
    vector<bool> visited(M.size(), false);
    int ans = 0;
    for(int p1=0; p1<(int)visited.size(); p1++){
        if (!visited[p1]) {
            visited[p1] = true;
            ans++;
            ExpandCircle(M, p1, visited);
        }
    }
    return ans;
}

void ExpandCircle(const vector<vector<int>>& M, int p1, vector<bool>& visited){
    for(int p2=0; p2<(int)visited.size(); p2++){
        if (M[p1][p2] && !visited[p2]) {
            visited[p2] = true;
            ExpandCircle(M, p2, visited);
        }
    }
}











void print(vector<vector<int>>& M){
    for(int r=0;r<(int)M.size();r++){
        for(int c=0;c<(int)M[0].size();c++){
            cout << M[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
