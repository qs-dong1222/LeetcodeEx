#include <iostream>
#include <vector>

using namespace std;
bool isMatch(string str, string pat);

int main(){
    string str = "qaadgc";
    string pat = "q.*d.";

    cout << isMatch(str, pat) << endl;

    return 0;
}


/*
这道题比较难:
首先subproblem就不好想, match[i][j] 表示 原字符串str[0 : i-1]与pat[0 : j-1] 的匹配情况.
看到 i->i-1 的这种对应关系，说明肯定会在dp矩阵里多出一行一列的边界值，这个边界值我们要自己初始化。
关键思想是:
1. 碰到相同的字符或者'.', 说明我们可以把这个当前相同的字符以删除，仅仅看前面的字符匹配情况
2. 碰到'*', '*'不能独立存在，前面必须有一个非*字符。
3. 碰到'*', 要么其任何作用没有，仅仅看两个字符前的匹配情况即可。要么'*'至少代表一个字符
   此时的原字符串中的当前字符如果匹配，则可将其删除，pat中'*'可能存在多个重复字符，所以将其保留，
   再对删改过的原字符串进行进一步匹配.
*/
bool isMatch(string str, string pat) {
    // match[i][j] stands for
    // does str[0 : i-1] match pat[0 : j-1] ?
    vector<vector<bool>> match(str.size()+1, vector<bool>(pat.size()+1, false));

    match[0][0] = true; // empty str for sure matches empty pat

    // initialize 0th row, i.e. match[0][j] ->  empty str match pat[0:j-1]?
    for(int j=2;j<=(int)pat.size();j++){
        // pat cannot have any char, so only "*" is available
        if(j==1 && pat[j-1]=='*'){ // pat[0:1-1] = pat[0]
            match[0][j] = true;
        }
        else if(pat[j-1]=='*'){
            match[0][j] = match[0][j-2];
        }
    }

    for(int i=1;i<(int)match.size();i++){
        for(int j=1;j<(int)match[0].size();j++){
            if(pat[j-1]==str[i-1] || pat[j-1]=='.'){
                // str[i-1] matches with pat[j-1], we can remove those 2 chars and see
                // the previous matching condition in rest of chars
                match[i][j] = match[i-1][j-1];
            }
            // pat[j-1] is '*' and has at least 2 chars
            else if(pat[j-1]=='*' && j>1){
//                // if '*' represents 0 forehead chars, we remove forehead char and '*' from pat
//                if(0 forehead chars){
//                    match[i][j] = match[i][j-2];
//                }
//                // '*' represents at least 1 forehead char, so we can remove this char from str,
//                // there still may be repetitive chars, pat remains "foreCh*"
//                else if('*' at least represents 1 char && pat[j-2]==str[i-1]){
//                    match[i][j] = match[i-1][j];
//                }
                if( match[i][j-2] ||
                   ((pat[j-2]==str[i-1] || pat[j-2]=='.') && match[i-1][j])   ){
                    match[i][j] = true;
                }
            }
        }
    }

    return match[str.size()][pat.size()];
}
