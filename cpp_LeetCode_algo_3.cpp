#include <iostream>
#include <unordered_set>

using namespace std;

int SubstringStartWithIdx(string& s, int idx);
int lengthOfLongestSubstring(string s);

int main(){
    string txt = "abcabcdebb";
//    int ans = 0;
//    for(int i=0;i<(int)txt.size();i++){
//        ans = max(SubstringStartWithIdx(txt, i), ans);
//    }
//    cout <<ans << endl;

    cout << lengthOfLongestSubstring(txt) << endl;

    return 0;
}


//int SubstringStartWithIdx(string& s, int idx) {
//    unordered_set<char> charSet;
//    int ans = 0;
//    for(int i=idx; i<(int)s.size(); i++){
//        if(charSet.count(s[i])){
//            return ans;
//        }
//        else{
//            ans++;
//            charSet.insert(s[i]);
//        }
//    }
//    return ans;
//}



/*
sliding window solution:
���algo����ţB.
����index i��j
jΪǰ��index
iΪ��index
�Ȳ鿴�Ƿ�s[j]�Ѿ����ֹ�
û���ֹ�: j++, length = max(ori_length, j-i)
���ֹ�: ���ٸı�j��˵����ʱ��s[i]��ͷ��substring�Ѿ�����ʹ�ˣ��෴�ģ�����Ӧ�û�һ���µĴ�ͷ�ģ���i++
        ͬʱɾ�����ֹ��ļ�¼�ַ�
*/
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_set<char> charSet;
    int ans = 0, i = 0, j = 0;
    while (i < n && j < n) {
        // try to extend the range [i, j]
        if (!charSet.count(s[j])){
            charSet.insert(s[j]);
            j++;
            ans = max(ans, j - i);
        }
        else {
            charSet.erase(s[i]);
            i++;
        }
    }
    return ans;
}
