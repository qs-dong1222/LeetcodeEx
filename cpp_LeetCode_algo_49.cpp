#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<int> WordCharCount(string& word);
bool IsSameChar(const string& s1, const string& s2);
string Encode(const string& s);

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



/*
solution 1 : 基于encode思想
*/
vector<vector<string>> groupAnagrams(vector<string>& words) {
    vector<vector<string>> ans;
    if(words.empty()) return ans;

    unordered_map<string, vector<string>> strmap;

    for(int i=0;i<(int)words.size();i++){
        string encodeStr = Encode(words[i]);
        strmap[encodeStr].push_back(words[i]);
    }

    for(auto each : strmap){
        ans.push_back(each.second);
    }

    return ans;
}

/*
利用基数排序的思想encode一个字符串，同字符构成的字符串，encode出来的结果一样，o(n)
*/
string Encode(const string& s){
    string ans(26, '0');
    if(s.empty()) return ans;

    for(int i=0;i<(int)s.size();i++){
         int oldcnt = ans[s[i]-'a'] - '0';
         ans[s[i]-'a'] = oldcnt+1+'0';
    }

    return ans;
}





/*
solution 2 : 同字符构成排序结果相同, 排序o(nlogn)
*/
//vector<vector<string>> groupAnagrams(vector<string>& words) {
//    vector<vector<string>> ans;
//    if(words.empty()) return ans;
//
//    unordered_map<string, vector<string>> strmap;
//
//    for(int i=0;i<(int)words.size();i++){
//        string tmp = words[i];
//        sort(tmp.begin(), tmp.end());
//        strmap[tmp].push_back(words[i]);
//    }
//
//    for(auto each : strmap){
//        ans.push_back(each.second);
//    }
//
//    return ans;
//}












/*
o(n) 判断两个字符串是否是同数量字符构成
*/
bool IsSameChar(const string& s1, const string& s2){
    if(s1.size()!=s2.size()) return false;

    vector<int> charcnt(128,0);
    for(int i=0;i<(int)s1.size();i++){
        charcnt[s1[i]-'0']++;
        charcnt[s2[i]-'0']--;
    }

    for(int i=0;i<(int)charcnt.size();i++){
        if(charcnt[i]!=0) return false;
    }

    return true;
}


