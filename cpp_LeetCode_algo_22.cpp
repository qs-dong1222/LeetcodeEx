#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<string>& ans, int nLeftHasPut, int nRightHasNotPut, string& curr);
vector<string> generateParenthesis(int n);

int main(){
    int n = 3;

//    unordered_set<string> ans;
//    string str = "";
    //genParenthe(str, 3, 0, ans);

    vector<string> ans = generateParenthesis(3);

    for(auto each:ans){
        cout << each << endl;
    }

    return 0;
}




vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if(n==0) return ans;
    string curr;
    dfs(ans, n, 0, curr);
    return ans;
}



void dfs(vector<string>& ans, int leftCanPut, int leftNeed2Match, string& curr){
    if(leftCanPut == 0 && leftNeed2Match == 0){
        ans.push_back(curr);
        return;
    }

    if(leftCanPut){
        curr.push_back('(');
        dfs(ans, leftCanPut-1, leftNeed2Match+1, curr);
        curr.pop_back();
    }

    if(leftNeed2Match){
        curr.push_back(')');
        dfs(ans, leftCanPut, leftNeed2Match-1, curr);
        curr.pop_back();
    }
}
