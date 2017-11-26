#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows);

int main(){
    vector<vector<int>> ans = generate(5);

    for(auto eachRow :ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout <<endl;
    }

    return 0;
}


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if(numRows == 0) return ans;

    ans.push_back(vector<int>(1,1));

    for(int i=1;i<numRows;i++){
        vector<int> padding(ans[i-1].begin(), ans[i-1].end());
        padding.insert(padding.begin(), 0);
        padding.insert(padding.end(),0);
        vector<int> curr;
        for(int j=1;j<padding.size();j++){
            curr.push_back(padding[j-1] + padding[j]);
        }
        ans.push_back(curr);
    }

    return ans;
}
