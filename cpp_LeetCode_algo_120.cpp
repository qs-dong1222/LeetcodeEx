#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& triangle, int row, int col, int& curr, int& ans);
int minimumTotal(vector<vector<int>>& triangle);

int main(){
    vector<vector<int>> triangle =
    {
         {2},
        {3,4},
       {6,5,7},
      {4,1,8,3}
    };


    cout << minimumTotal(triangle) << endl;

    return 0;
}



/*
DP: 比较完整的想出了递推形式的dp。
题目要求最少路径和，且要求o(k) (k=最后一行size) 的最小空间。那么就是生命一个 k-elem 的vector
以main()函数中德例子来看，最后有4个elem，每个elem很显然要存 以相应位置最为结束点时，最小的path sum
那么新的一行统计就应该等于上一次dp时的那一行加上能走的路径点中最小的那一支，当走到两头时，只有
一个支线能走。
*/
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.empty()) return 0;

    vector<int> ans( triangle[triangle.size()-1].size(), 0);
    ans[0] = triangle[0][0];

    for(int r=1; r<triangle.size(); r++){
        vector<int> backup = ans;
        ans[triangle[r].size()-1] = backup[triangle[r].size()-2] + triangle[r][triangle[r].size()-1];
        ans[0] = backup[0] + triangle[r][0];
        for(int c=triangle[r].size()-2; c>=1; c--){
            ans[c] = min(triangle[r][c]+backup[c-1], triangle[r][c]+backup[c]);
        }
    }

    int res = INT_MAX;
    for(auto each : ans){
        res = min(each, res);
    }
    return res;
}




/*
DFS: time limit exceeded
*/
//int minimumTotal(vector<vector<int>>& triangle) {
//    int curr = triangle[0][0];
//    int ans = INT_MAX;
//    DFS(triangle, 0, 0, curr, ans);
//    return ans;
//}
//
//void DFS(vector<vector<int>>& triangle, int row, int col, int& curr, int& ans){
//    if(triangle.empty()) ans = 0;
//    if(row==triangle.size()-1){
//        ans = min(ans, curr);
//        return;
//    }
//
//    curr += triangle[row+1][col];
//    DFS(triangle, row+1, col, curr, ans);
//    curr -= triangle[row+1][col];
//
//    curr += triangle[row+1][col+1];
//    DFS(triangle, row+1, col+1, curr, ans);
//    curr -= triangle[row+1][col+1];
//}
