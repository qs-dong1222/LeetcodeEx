#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <deque>

using namespace std;

int main(){

    return 0;
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    if(s.empty()) return ans;

    vector<string> curr;
    DFS(s, 0, curr, ans);
    return ans;
}

// collect palindrome substring from startIdx to the end
void DFS(string& str, int startIdx, vector<string>& curr, vector<vector<string>>& ans){
    if(startIdx >= str.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=startIdx; i<str.size(); i++){
        if(IsPalindrome(str, startIdx, i)){
            curr.push_back(str.substr(startIdx, i-startIdx+1));
            // if startIdx ~ i is palindrome, check if rest of string is palindrome
            DFS(str, startIdx+1, curr, ans);
            curr.pop_back();
        }
    }
}


bool IsPalindrome(string& str, int startIdx, int endIdx){
    while(startIdx<=endIdx){
        if(str[startIdx] != str[endIdx])
            return false;
        else{
            startIdx++;
            endIdx--;
        }
    }
    return true;
}
