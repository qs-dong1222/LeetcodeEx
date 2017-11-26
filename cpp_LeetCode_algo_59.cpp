#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n);

int main(){
    vector<vector<int>> ans = generateMatrix(3);

    for(auto eachRow:ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}



vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans;
    if(n==0) return ans;
    ans = vector<vector<int>>(n, vector<int>(n,0));

    int r,c;
    int rbegin = 0;
    int rend = ans.size()-1;
    int cbegin = 0;
    int cend = ans[0].size()-1;
    const int TOT = n*n;
    int cnt = 0;


    while(true){
        if(rbegin>rend || cbegin>cend) break;

        r = rbegin;
        for(c=cbegin;c<=cend;c++){
            cnt++;
            ans[r][c] = cnt;
        }
        if(cnt==TOT) break;

        c--;
        for(r=rbegin+1; r<=rend; r++){
            cnt++;
            ans[r][c] = cnt;
        }
        if(cnt==TOT) break;

        r--;
        for(c=cend-1;c>=cbegin;c--){
            cnt++;
            ans[r][c] = cnt;
        }
        if(cnt==TOT) break;

        c++;
        for(r=rend-1; r>=rbegin+1; r--){
            cnt++;
            ans[r][c] = cnt;
        }
        if(cnt==TOT) break;

        rbegin++;
        rend--;
        cbegin++;
        cend--;
    }

    return ans;
}
