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
DP: �Ƚ�����������˵�����ʽ��dp��
��ĿҪ������·���ͣ���Ҫ��o(k) (k=���һ��size) ����С�ռ䡣��ô��������һ�� k-elem ��vector
��main()�����е����������������4��elem��ÿ��elem����ȻҪ�� ����Ӧλ����Ϊ������ʱ����С��path sum
��ô�µ�һ��ͳ�ƾ�Ӧ�õ�����һ��dpʱ����һ�м������ߵ�·��������С����һ֧�����ߵ���ͷʱ��ֻ��
һ��֧�����ߡ�
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
