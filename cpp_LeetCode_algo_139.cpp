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


bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    //separatable[j] : if s[0:j-1] is separatable
    vector<bool> separatable(s.size(), false);

    for(int i=0;i<(int)s.size();i++){
        for(int j=i; j<(int)s.size(); j++){
            // if s[i]~s[j] is a word, then see if s[0:i-1] is separatable
            if( wordSet.count(s.substr(i, j-i+1)) ){
                if(i-1<0){
                    separatable[j] = true;
                }
                else if(separatable[i-1] && i-1>=0){
                    separatable[j] = true;
                }
            }
        }
    }

    return seperatable[s.size()-1];
}


