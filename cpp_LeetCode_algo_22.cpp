#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//void genParenthe(const string& str, int left2use, int right2add, unordered_set<string>& ans);
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


void dfs(vector<string>& ans, int nLeft2Put, int nLeftExisted, string& curr){
    if(nLeftExisted==0 && nLeft2Put==0){
        ans.push_back(curr);
        return;
    }

    if(nLeft2Put>0){
        curr.push_back('(');
        dfs(ans, nLeft2Put-1, nLeftExisted+1, curr);
        curr.pop_back();
    }

    if(nLeftExisted>0){
        curr.push_back(')');
        dfs(ans, nLeft2Put, nLeftExisted-1, curr);
        curr.pop_back();
    }
}








void genParenthe(const string& str, int left2use, int right2add, unordered_set<string>& ans){
    if(left2use==0 && right2add==0){
        ans.insert(str);
        return;
    }

    if(left2use > 0)
        genParenthe(str+'(', left2use-1, right2add+1, ans );

    if(right2add > 0)
        genParenthe(str+')', left2use, right2add-1, ans );

}
