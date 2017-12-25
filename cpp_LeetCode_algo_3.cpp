#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int SubstringStartWithIdx(string& s, int idx);
int lengthOfLongestSubstring(string s);





int main(){
    string txt = "abcabcbb";
//    string txt = "pwwkew";
//    string txt = "abba";
//    string txt = "tmmzuxt";

    cout << lengthOfLongestSubstring(txt) << endl;

    return 0;
}


int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;

    unordered_map<char, int> charIdx;
    int startIdx = 0;
    int ans = 1;
    for(int i=0;i<s.size();i++){
        if(!charIdx.count(s[i]) || charIdx[s[i]]<startIdx){
            ans = max(ans, i-startIdx+1);
        }
        else{
            startIdx = charIdx[s[i]]+1;
        }
        charIdx[s[i]] = i;
    }

    return ans;
}


///*
//sliding window solution:
//拿俩index i和j
//j为前部index
//i为后部index
//先查看是否s[j]已经出现过
//没出现过: j++, length = max(ori_length, j-i)
//出现过: 不再改变j，说明此时以s[i]打头的substring已经不好使了，相反的，我们应该换一个新的打头的，即i++
//        同时删除出现过的记录字符
//*/
//int lengthOfLongestSubstring(string s) {
//    int n = s.length();
//    unordered_set<char> charSet;
//    int ans = 0, i = 0, j = 0;
//    while (i < n && j < n) {
//        // try to extend the range [i, j]
//        if (!charSet.count(s[j])){
//            charSet.insert(s[j]);
//            j++;
//            ans = max(ans, j - i);
//        }
//        else {
//            charSet.erase(s[i]);
//            i++;
//        }
//    }
//    return ans;
//}
