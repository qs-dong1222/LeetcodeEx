#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<int> findSubstring(string s, vector<string>& words);

int main(){
    vector<string> words = {"foo", "bar"};

    vector<int> ans = findSubstring("barfoothefoobarman", words);

    for(auto each:ans){
        cout << each << " ";
    }

    return 0;
}




vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if(s.empty() || words.empty()) return ans;

    unordered_map<string, int> wordCnt;
    int wordLen = words[0].size();
    for(int i=0;i<(int)words.size();i++){
        if(wordCnt.count(words[i])) wordCnt[words[i]]++;
        else wordCnt[words[i]] = 1;
    }


    int wordsNbr = words.size();
    unordered_map<string, int> wordCntCopy = wordCnt;
    int wordsNbrCopy = wordsNbr;
    for(int startPos=0; startPos<=(int)(s.size()-wordsNbr*wordLen); startPos++){
        wordsNbr = wordsNbrCopy;
        wordCnt = wordCntCopy;
        for(int i=startPos;i<(int)s.size()-wordsNbr*wordLen;i+=wordLen){
            string tmpstr = s.substr(i, wordLen);
            if(!wordCnt.count(tmpstr)){
                break;
            }
            else if(wordCnt[tmpstr]<=0){
                break;
            }
            else{
                wordCnt[tmpstr]--;
                wordsNbr--;
            }

            if(wordsNbr==0){
                ans.push_back(startPos);
                break;
            }
        }

    }

    return ans;
}

