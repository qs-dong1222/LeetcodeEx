#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;
bool wordBreak(string s, vector<string>& wordDict);

int main(){

    vector<string> dict = {"we", "are", "the", "champion", "world", "beat"};

    string s = "wearetheworld";

    cout << wordBreak(s, dict) << endl;

}


/*
DP No.1, 以各个字符为搜索标准
*/
//bool wordBreak(string s, vector<string>& wordDict) {
//    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//    //separatable[j] : if s[0:j-1] is separatable
//    vector<bool> separatable(s.size(), false);
//
//    for(int i=0;i<(int)s.size();i++){
//        for(int j=i; j<(int)s.size(); j++){
//            // if s[i]~s[j] is a word, then see if s[0:i-1] is separatable
//            if( wordSet.count(s.substr(i, j-i+1)) ){
//                if(i-1<0){
//                    separatable[j] = true;
//                }
//                else if(separatable[i-1] && i-1>=0){
//                    separatable[j] = true;
//                }
//            }
//        }
//    }
//
//    return separatable[s.size()-1];
//}




/*
DP No.2, 以各个单词为搜索标准
*/
bool wordBreak(string s, vector<string>& wordDict) {
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

