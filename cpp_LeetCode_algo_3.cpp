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
//����index i��j
//jΪǰ��index
//iΪ��index
//�Ȳ鿴�Ƿ�s[j]�Ѿ����ֹ�
//û���ֹ�: j++, length = max(ori_length, j-i)
//���ֹ�: ���ٸı�j��˵����ʱ��s[i]��ͷ��substring�Ѿ�����ʹ�ˣ��෴�ģ�����Ӧ�û�һ���µĴ�ͷ�ģ���i++
//        ͬʱɾ�����ֹ��ļ�¼�ַ�
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
