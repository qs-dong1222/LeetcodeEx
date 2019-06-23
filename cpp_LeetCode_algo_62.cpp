#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int FindNbrOfPathAtCoord(int r, int c);
unordered_map<int, int> resMap;
int uniquePaths(int m, int n);
int nPathAtCoord(int r, int c);
void dfs(int n, int m, int curr_r, int curr_c, int& ans);

int main(){

    cout << uniquePaths(2,2) << endl;

    return 0;
}





/*
  solution: bottom-up dp
            思路比较简单, 就是dp的每一个格子表示: 跑到此位置有多少种可能
*/
//int uniquePaths(int m, int n) {
//    if(m<0 || n<0) return 0;
//
//    return nPathAtCoord(m-1, n-1);
//}
//int nPathAtCoord(int r, int c){
//    int key = (r*13<<3) + c;
//    if(resMap.count(key)){
//        return resMap[key];
//    }
//
//    if(r==0 && c==0){
//        return 1;
//    }
//    else if(r==0 && c!=0){
//        resMap[key] = nPathAtCoord(r, c-1);
//    }
//    else if(r!=0 && c==0){
//        resMap[key] = nPathAtCoord(r-1, c);
//    }
//    else{
//        resMap[key] = nPathAtCoord(r-1, c) + nPathAtCoord(r, c-1);
//    }
//    return resMap[key];
//}



/*
    solution: top-down dp
*/
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int c=0; c<m; c++){
        dp[0][c] = 1;
    }

    for(int r=0; r<n; r++){
        dp[r][0] = 1;
    }

    for(int r=1; r<n; r++){
        for(int c=1; c<m; c++){
            dp[r][c] = dp[r-1][c] + dp[r][c-1];
        }
    }

//    for(auto eachRow : dp){
//        for(auto eachCol : eachRow){
//            cout << eachCol << " ";
//        }
//        cout << endl;
//    }

    return dp[n-1][m-1];
}




/*
    solution: dfs
    这种解法虽然没错, 但是时间复杂度很高, 是暴力解法
    费时的原因: 每一个结点都会有 向右和向下 两个后行分支, 分别构成搜索树.
                同时从之前的搜索路线到达当前这个节点又有 从上和从左 两个先行分支.
                这些分支排列组合有4种可能, 但是两个后行分支搜路线对于两个先行分支是
                一模一样的重复操作, 相当于做了每个节点做了一边重复的操作.
*/
//int uniquePaths(int m, int n) {
//    int ans = 0;
//    dfs(n, m, 0, 0, ans);
//    return ans;
//}
//
//
//void dfs(int n, int m, int curr_r, int curr_c, int& ans){
//    if(curr_r == n-1 && curr_c == m-1){
//        ans++;
//        return;
//    }
//
//    if(curr_r == n-1){
//        dfs(n, m, curr_r, curr_c+1, ans);
//    }
//    else if(curr_c == m-1){
//        dfs(n, m, curr_r+1, curr_c, ans);
//    }
//    else{
//        dfs(n, m, curr_r+1, curr_c, ans);
//        dfs(n, m, curr_r, curr_c+1, ans);
//    }
//}


