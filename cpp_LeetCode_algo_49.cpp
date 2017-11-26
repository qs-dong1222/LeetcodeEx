#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
//void Permute(string& word, int begin, unordered_set<string>& ans);
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<int> WordCharCount(string& word);

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans;

    ans = groupAnagrams(strs);

    for(auto eachGroup:ans){
        for(auto eachStr : eachGroup){
            cout <<eachStr << " ";
        }
        cout << endl;
    }

    return 0;
}


//void Permute(string& word, int begin, unordered_set<string>& ans){
//    if(begin >= word.size()){
//        ans.insert(word);
//        return;
//    }
//
//    for(int i=begin;i<word.size();i++){
//        swap(word[begin], word[i]);
//        Permute(word, begin+1, ans);
//        swap(word[begin], word[i]);
//    }
//}
//
//vector<vector<string>> groupAnagrams(vector<string>& strs) {
//    if(strs.empty()) return vector<vector<string>>(0,vector<string>(0,""));
//    unordered_set<string> permuteGroup;
//    vector<string> partialRes;
//    vector<vector<string>> ans;
//
//    while(!strs.empty()){
//        permuteGroup.clear();
//        partialRes.clear();
//        Permute(strs[0], 0, permuteGroup);
//        partialRes.push_back(strs[0]);
//        strs.erase(strs.begin());
//
//        vector<string>::iterator it = strs.begin();
//        for(int i=0; i<strs.size(); i++){
//            if(permuteGroup.count(strs[i])){
//                partialRes.push_back(strs[i]);
//                strs.erase(i+strs.begin());
//                i--;
//            }
//        }
//        ans.push_back(partialRes);
//    }
//
//    return ans;
//}


vector<vector<string>> groupAnagrams(vector<string>& strs){
    if(strs.empty()) return vector<vector<string>>(0,vector<string>(0,""));
    vector<int> charOccur(26,0);
    vector<string> partialRes;
    vector<vector<string>> ans;

    while(!strs.empty()){
        partialRes.clear();
        charOccur = WordCharCount(strs[0]);
        partialRes.push_back(strs[0]);
        strs.erase(strs.begin());

        vector<string>::iterator it = strs.begin();
        for(int i=0; i<(int)strs.size(); i++){
            if( WordCharCount(strs[i]) == charOccur ){
                partialRes.push_back(strs[i]);
                strs.erase(i+strs.begin());
                i--;
            }
        }
        ans.push_back(partialRes);
    }

    return ans;
}


vector<int> WordCharCount(string& word){
    vector<int> charOccur(26, 0);

    for(auto each : word){
        charOccur[each-'0']++;
    }

    return charOccur;
}

