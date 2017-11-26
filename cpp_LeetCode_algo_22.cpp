#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void genParenthe(const string& str, int left2use, int right2add, unordered_set<string>& ans);

int main(){
    int n = 3;

    unordered_set<string> ans;
    string str = "";

    genParenthe(str, 3, 0, ans);

    for(auto each:ans){
        cout << each << endl;
    }

    return 0;
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


//[,,,,,,,,,,,,]
//[,,,,,,,"(())(())",,,,,,]
