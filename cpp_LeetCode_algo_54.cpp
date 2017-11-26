#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main(){
    vector<vector<int>> mat =
    {
     { 1, 2, 3 },
     { 4, 5, 6 },
     { 7, 8, 9 }
    };

    vector<int> ans = spiralOrder(mat);

    for(auto each : ans){
        cout << each << " ";
    }

    return 0;
}



vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.empty()) return vector<int>(0);
    int r,c;
    int rbegin = 0;
    int rend = matrix.size()-1;
    int cbegin = 0;
    int cend = matrix[0].size()-1;
    const int TOT = matrix.size() * matrix[0].size();
    int cnt = 0;
    vector<int> ans;

    while(true){
        if(rbegin>rend || cbegin>cend) break;

        r = rbegin;
        for(c=cbegin;c<=cend;c++){
            ans.push_back(matrix[r][c]);
            cnt++;
        }
        if(cnt==TOT) break;

        c--;
        for(r=rbegin+1; r<=rend; r++){
            ans.push_back(matrix[r][c]);
            cnt++;
        }
        if(cnt==TOT) break;

        r--;
        for(c=cend-1;c>=cbegin;c--){
            ans.push_back(matrix[r][c]);
            cnt++;
        }
        if(cnt==TOT) break;

        c++;
        for(r=rend-1; r>=rbegin+1; r--){
            ans.push_back(matrix[r][c]);
            cnt++;
        }
        if(cnt==TOT) break;

        rbegin++;
        rend--;
        cbegin++;
        cend--;
    }

    return ans;
}
