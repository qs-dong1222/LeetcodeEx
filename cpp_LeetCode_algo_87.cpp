#include <iostream>
#include <vector>

using namespace std;
bool isScramble(string s1, string s2);

int main(){
    string s1 = "abc";
    string s2 = "bca";

    isScramble(s1,s2);

    return 0;
}




/*
Leetcode上的神法无一不是牛B法：
此法的根源来自于分割：
假如有原字符串 great, 我们分成两部分，第一部分gr, 第二部分eat
gr 和 eat都有下属分支。 假如说我们有一个scramble的字符串 rgate, 我们在同样的位置上分割，得到
rg 和 ate, 显然rg是从gr进行scram得来的，ate是从eat进行scram得来的，这么一来我们只要确保两部分
都是scramable的就可以了。还有一种情况是 gr和eat换了，变成eatgr，这种情况下我们要把原字符串的
前部和待匹配字符串的后部进行匹配。
*/
bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size())
        return false;

    if(s1==s2)
        return true;

    // 看是否两字符串由相同数量的字母构成
    vector<int> chars(26,0);
    for(int i=0;i<s1.size();i++){
        chars[s1[i]-'a']++;
        chars[s2[i]-'a']--;
    }
    for(auto each : chars){
        if(each != 0)
            return false;
    }

    // 在各个位置上进行分割，分割为两个子字符串，如果两个子字符串都是scramble，那么整体就是sramble的
    for(int i=1;i<s1.size();i++){
        if( isScramble(s1.substr(0,i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)) )
            return true;
        if( isScramble(s1.substr(0,i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i)) )
            return true;
    }
    return false;
}
