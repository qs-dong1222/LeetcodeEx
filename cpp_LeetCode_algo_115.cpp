#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct STR_POS{
    string str;
    string posrecord;
};

int numDistinct(string s, string t);
string recoverStr(string& s, vector<bool>& pos);
void DFS(string& s, string& t, int& ans, vector<bool>& pos, unordered_set<vector<bool>>& visited);
bool isS1hasS2(string& s1, string& s2);

int main(){

    string s = "ccc";
    string t = "c";

    cout << numDistinct(s, t) << endl;

//    vector<bool> pos = {false, false, true, false, true};
//    string s = "12345";
//    cout << recoverStr(s,pos) << endl;

    return 0;
}



/*
每每看到大神们在这种难题上提出的dp解法，都感到无从下手，力不从心，自己思维有限，只有从他山之玉习得攻石之法.
解法思路：
假如有一个字符串 s: ...a...a...b..b...c..c.. , '.'表示其他闲杂字符
另有一匹配字符串 t: abc

我们如果一个个手动排列组合的话，要想凑齐abc，就相当于是C21取a,C21取b,C21取c，总共有8种组合
换句话说，我们可以先去挑a。那么在a的选择上，第一个a只有C11一种选择，而第二个a就有C21两种选择
再去挑b。由于b是在a后面，所以b之前如果没出现a，就不用考虑了，而如果b之前出现了a，说明我们应该结合
a的出现情况，就比如说例子中第一个b，前面有两个a，那么第一个b组成"ab"的情况就是2种，反观第二个b，
由于之前已经出现了一个"ab",同时前面还有两个a，那么组成"ab"的情况就是C21*C21=4种. 以此类推，直到
我们把t撸完。

所以我们可以先统计第一个字符'a':
...a.....a.....b.....b......c.....c.....
00011..11222..222222222.............2222 -> 'a'

同理我们再统计第二个字符b，即"ab"基于'a'的统计:
...a.....a.....b.....b......c.....c.....
00011..11222..22222222222222222222222222 -> 'a'
0000.........0022..22444...............4 -> "ab"
可以看出b的统计是它左边的那个数和上边的那个数的和，这也应和了我们C21*C21的情况

同理统计c,基于"ab":
...a.....a.....b.....b......c.....c.....
00011..11222..22222222222222222222222222 -> 'a'
0000.........0022..22444....4.....4....4 -> "ab"
000.......................00444..488...8 -> "abc"

看到这，很明显是一个递推的求解过程。那我们就要考虑边界条件。
这里就是针对第一行'a'的统计来说的，由于在递推里面，我们每个dp的操作都是一样的，即加dp左边那个和上面那个数。
那么对于第一行'a'，我们肯定的有个让a去加的上面一行东西，这里很明显的一排'1',这样才能保证有正确的'a'统计。
同时，由于dp还要加左边那个数，那么对于第一列，我们肯定也要初始化一个边界。假如说我们第一个字符就是'a'，
那么我们们没左边的东西能加，而且我们这个a的统计结果应该是1，那么我们就得在左边加一列初始化为0的padding，
这样才能正确开始运算。
这也符合递推型dp的结构，dp个数应为解的个数+1，二维的话就是(row+1)*(col+1).

那么回过头来，我们看看这个dp[i][j]的物理意义是什么:
对于一个数，比如上面'a'统计的第一个a而言，dp[i][j]的意思就是，在s[0:j-1]经delete后substring t[0:i-1]
可能的出现次数。
那么我们就想到边界条件上的数，比如dp[0][2]，就是s[0:2-1]=s[0:1]经delete后substring t[0:0-1]=t[0:-1]可能的出现次数。
t[0:-1]其实就是空字符串，所以第一行边界条件就是 t为空时，s[0:j-1]中出现t的出现可能，那就一种可能，就是
s[0:j-1]的字符全删了。所以第一排边界条件全是1.
而对于第一列边界条件而言，比如dp[3][0]，表示 s[0:0-1]=s[0:-11]经delete后substring t[0:3-1]=t[0:2]可能的出现次数。
即s是空字符串，那根本不可能包含t，所以第一列边界条件全是0。


纵观全篇，这种dp的运行速度应该非常快。但是太难想，下回碰到子字符串的删减的这种难题，可以先试着从一个个字符入手试试看。
*/
int numDistinct(string& s, string& t) {
    int n = s.length();
    int m = t.length();

    int dp[n+1][m+1];

    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j < m+1; j++) {
        dp[0][j] = 0;
    }

    for (int j = 1; j < m+1; j++) {
        for (int i = 1; i < n+1; i++) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1] == t[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];
}






/*
DFS solution: time limit exceeded
*/
//int numDistinct(string s, string t) {
//    int ans = 0;
//    vector<bool> pos(s.size(), true);
//    unordered_set<vector<bool>> visited;
//
//    DFS(s, t, ans, pos, visited);
//    return ans;
//}
//
//void DFS(string& s, string& t, int& ans, vector<bool>& pos, unordered_set<vector<bool>>& visited){
//    string curr = recoverStr(s, pos);
//
//    if(curr.size() < t.size() || !isS1hasS2(curr, t) ){
//        return;
//    }
//
//    if(curr == t){
//        if(!visited.count(pos)){
//            visited.insert(pos);
//            ans++;
//        }
//        return;
//    }
//
//    // curr.size() is still > t.size(), need more delete
//    for(int i=0;i<s.size();i++){
//        if(!pos[i])
//            continue;
//        pos[i] = false;
//        DFS(s, t, ans, pos, visited);
//        pos[i] = true;
//    }
//}
//
//string recoverStr(string& s, vector<bool>& pos){
//    string ans;
//    for(int i=0;i<s.size();i++){
//        if(pos[i])
//            ans.push_back(s[i]);
//    }
//    return ans;
//}
//
//bool isS1hasS2(string& s1, string& s2){
//    vector<int> chars(128, 0);
//
//    for(int i=0;i<s2.size();i++){
//        chars[s2[i]]++;
//    }
//
//    for(int i=0;i<s1.size();i++){
//        chars[s1[i]]--;
//    }
//
//    for(auto each:chars){
//        if(each > 0)
//            return false;
//    }
//
//    return true;
//}


