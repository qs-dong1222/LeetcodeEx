#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <deque>

using namespace std;

void foo(string& s, int start, int& cut);
bool IsPalindrome(string& str, int startIdx, int endIdx);
int minCut(string s);

int main(){
    string s = "aab";

    cout << minCut(s) << endl;

    return 0;
}




/*
回文DP的一般思路：
回文有三种可能的形式:
1.单个字符
2.两个相同的字符
3.两头字符相同，中间的子字符串也是回文
所以我们可以用一个矩阵pli[i][j]来表示从s[i]到s[j]的回文有效性.
那么我们就需要n*n=n^2的循环，这个循环可以从后面s[end]开始，也可以从s[0]开始。
每每走到s[i][j=i]都是true，s[i][j=i+1]都查看一下双字符情况.

在这到题里我们需要寻找mincut. 字符串从前往后看的话，pli[i][j]顺序是:
pli[0][0] pli[0][1] pli[0][2] ... pli[0][end],   pli[1][1] pli[1][2] ... pli[1][end] ...
从后往前看的话类似。

但是mincut可以从后往前递推，mincut[i]表示s[i:end]中的mincut个数. 从前往后的话，没办法保证mincut的更新。
如果pli[i][j]是有效回文，那么在更新mincut[j]即可。

if(isPli[i][j]){
    if(j==(int)s.size()-1)
        mincut[i] = 0;
    else
        mincut[i] = min(mincut[i], mincut[j+1]+1);
}
说明了j=end的时候我们应该是没有cut的。
而更新过程中有可能临时会出现多余的cut，这个min()就是为了保证这个mincut一直保持在最小状态下的解.
*/
int minCut(string s){
    if(s.empty()) return 0;
    bool isPli[s.size()][s.size()] = {false};
    vector<int> mincut(s.size(), INT_MAX);

    for(int i=(int)s.size()-1; i>=0; i--){
        for(int j=i; j<(int)s.size(); j++){
            // set palindrome correctness
            if(i==j)
                isPli[i][j] = true;
            else if(j==i+1)
                isPli[i][j] = s[j]==s[i]? true:false;
            else
                isPli[i][j] = (s[i]==s[j])&&(isPli[i+1][j-1])? true:false;

            // look for mincut[i] for s[i:end]
            if(isPli[i][j]){
                if(j==(int)s.size()-1)
                    mincut[i] = 0;
                else
                    mincut[i] = min(mincut[i], mincut[j+1]+1);
            }
        }
    }

    return mincut[0];
}




bool IsPalindrome(string& str, int startIdx, int endIdx){
    while(startIdx<=endIdx){
        if(str[startIdx] != str[endIdx])
            return false;
        else{
            startIdx++;
            endIdx--;
        }
    }
    return true;
}
