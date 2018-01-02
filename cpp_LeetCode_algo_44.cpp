#include <iostream>
#include <vector>

using namespace std;
bool isMatch(string s, string p);

int main(){
    string s =
    "abcljqwmdc";

    string p =
    //"ab*km?dc";
    //"ab*";
    //"abc?*";
    "ab*w??*";


    cout << isMatch(s, p) << endl;


    return 0;
}




/*
solution: 这道题和第10题其实很像，都用dp来解就可以了。下面说一下细节思路。
1. match[i][j]的表示含义和第10题是一样的。
2. 对于 p[j-1]=s[i-1] 或 p[j-1]='?' 的情况，我们在pat和ori中都删去当前的pat[j-1]和ori[i-1]，
   再看之前的字符串匹配情况就可以了, 即看match[i-1][j-1]
3. 如果当前pat[j-1]='*'
   1)如果'*'匹配空字符, 我们就看pat删掉'*'后的匹配情况, 即看match[i][j-1]
   2)如果'*'匹配至少一个字符.
     2.1)'*'匹配的是ori中后续待匹配字符串中的首字符, 我们在ori和pat中各删除字符, 看match[i-1][j-1]即可
     2.2)'*'匹配的是ori中后续待匹配字符串中的非首字符, 我们就去看用'*'向ori的前一位进行匹配会有什么结果, 即看match[i-1][j]
   以上这三种情况有一个是true, 都可以使得匹配成立
*/
bool isMatch(string s, string p) {
    if(p.empty() && s.empty()) return true;

    vector<vector<bool>> match(s.size()+1,vector<bool>(p.size()+1, false));

    match[0][0] = true;
    for(int j=1;j<(int)match[0].size();j++){
        if(p[j-1]=='*'){
            match[0][j] = match[0][j-1];
        }
    }

    for(int i=1;i<(int)match.size();i++){
        for(int j=1;j<(int)match[0].size();j++){
            if(p[j-1]==s[i-1] || p[j-1]=='?'){
                match[i][j] = match[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                match[i][j] = (match[i][j-1] || match[i-1][j-1] || match[i-1][j]);
            }
        }
    }

    return match[match.size()-1][match[0].size()-1];
}
