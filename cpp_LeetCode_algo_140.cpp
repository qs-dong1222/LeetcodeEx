#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;
void DFS(unordered_set<string>& wordSet, string& s, int start, string& curr, vector<string>& ans);
void DFS(vector<string>& wordList, string& s, int start, string& curr, vector<string>& ans);
vector<string> wordBreak(string s, vector<string>& wordDict);
bool Breakable(string s, vector<string>& wordDict)



int main(){
    vector<string> dict = {"we", "are", "the", "champion", "world", "beat"};
    string s = "wearetheworld";

    vector<string> ans = wordBreak(s, dict);

    for(auto eachStr : ans){
        cout << eachStr << endl;
    }

    return 0;
}


/*
if we use DFS + Breakable(), it will be acceptable
*/
bool Breakable(string s, vector<string>& wordDict) {
    vector<bool> separatable(s.size(), false);
    for(int i=0; i<(int)s.size(); i++){
        for(auto eachWord : wordDict){
            int wLen = eachWord.size();
            if(s.substr(i, wLen) == eachWord){
                if(i==0 || separatable[i-1]){
                    separatable[i+wLen-1] = true;
                }
            }
        }
    }

    return separatable[s.size()-1];
}


/*
DFS No.1 based on match each word in wordDict : TLE
*/
//vector<string> wordBreak(string s, vector<string>& wordDict) {
//    string curr;
//    vector<string> ans;
//
//    DFS(wordDict, s, 0, curr, ans);
//
//    return ans;
//}
//
//void DFS(vector<string>& wordList, string& s, int start, string& curr, vector<string>& ans){
//    if(start>=(int)s.size()){
//        curr.pop_back();
//        ans.push_back(curr);
//        return;
//    }
//
//    string backup = curr;
//    for(auto eachWord :wordList){
//        int wLen = eachWord.size();
//        string poentialStr = s.substr(start, wLen);
//        if( poentialStr == eachWord ){
//            curr += (poentialStr + " ");
//            DFS(wordList, s, start+wLen, curr, ans);
//            curr = backup;
//        }
//    }
//}


/*
DFS No.2 based on match each char in string with words in wordDict : TLE
*/
//vector<string> wordBreak(string s, vector<string>& wordDict) {
//    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//    string curr;
//    vector<string> ans;
//
//    DFS(wordSet, s, 0, curr, ans);
//
//    return ans;
//}

//void DFS(unordered_set<string>& wordSet, string& s, int start, string& curr, vector<string>& ans){
//    if(start>=(int)s.size()){
//        curr.pop_back();
//        ans.push_back(curr);
//        return;
//    }
//
//    string backup = curr;
//    for(int i=start; i<(int)s.size(); i++){
//        string substring = s.substr(start, i-start+1);
//        if( wordSet.count(substring) ){
//            curr += (substring + " ");
//            DFS(wordSet, s, i+1,curr, ans);
//            curr = backup;
//        }
//    }
//}




