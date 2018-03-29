#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k);
void helper(vector<vector<int>>& ans, vector<int>& curr, int start, int n, int k);


int main(){

    vector<vector<int>> ans = combine(4, 2);

    for(auto eachRow:ans){
        for(auto each:eachRow){
            cout << each <<" ";
        }
        cout << endl;
    }


    return 0;
}




vector<vector<int>> combine(int n, int k) {
    vector<int> curr;
    vector<vector<int>> ans;
    helper(ans, curr, 1, n, k);
    return ans;
}


void helper(vector<vector<int>>& ans, vector<int>& curr, int start, int n, int k){
    if((int)curr.size() >= k){
        ans.push_back(curr);
        return;
    }

    for(int i=start; i<=n; i++){
        curr.push_back(i);
        helper(ans, curr, i+1, n, k);
        curr.pop_back();
    }
}
