/*
有两个字符串,求将字符串2变为字符串1所需的最少步骤数
可选操作：
1) 删一个字符
2) 加一个字符
3) 换一个字符
*/

/*
解法：
这个题应该说是碰到的第一个上手的字符串DP问题.
关键点在于 : 题目里的加一个字符 是表示 在后面加一个字符, 即append
按照DP思路，咱们要求的是最少步骤数。那么我们的DP(x)就应该返回一个最少步骤数.
按照背包的思想，咱们首先想到的是一个个字符去处理DP.
关键是subproblem是怎么个思路。按照决策树的思想，我们要看对每个字符有几种操作。
这就需要我们拿个例子，试一试.
str1 = abcdef
str2 = bcde
如果我们的从决策树最高层开始处理，即所有字符都传入，我们应该去看DP(n-1)的情况.
DP(n-1) 到 DP(n) 需要什么？有几种可能性(有几种下属分支)？
1) str2[e]后面添一个字符去匹配str1, 那么就变成bcdef, 最后一个字符f至此操作完成，可以不去考虑，
   我们进而只考虑 str1 = abcde 和 str2 = bcde
   所以说一旦str2做操作2)，我们的下一步就是 str2(:) 和 str1(0:n-2)
2) 同理可以推出当做出操作1)时，我们的下一步应该是 str2(0:n-2) 和 str1(:)
3) 当两字符串一个字符做替换，那么另一个字符串的最后一位就会跟着匹配，那么我们的下一步就是
   str2(0:n-2) 和 str1(0:n-2)
上述的三种操作，都是一个步骤，那么在DP(x)中都会+1.

还有一种情况是：两个字符相等，那么可以同时剥去，而不进行DP(x)+1的操作.

综上 DP( str1(0:n), str2(0:n) ) = min(1+DP(增)/DP(删)/DP(换)) or DP( str1(0:n-1), str2(0:n-1) )
*/

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <unordered_map>
#include <stdlib.h>
#include <string>

using namespace std;


int FindMinEditSteps(string str1, string str2);
int FindMinEditSteps(string& str1, string& str2, int s1_idx, int s2_idx);
int minDistance(string word1, string word2);

unordered_map<string, int> resMap;

int main(){
    string str1 = "abcdef";
    string str2 = "cvf";

//    string str1 = "abc";
//    string str2 = "abcd";

//    cout <<FindMinEditSteps(str1, str2) <<endl;
    cout << minDistance(str1, str2) << endl;

    return 0;
}




// bot-up dp:
// 解释一下思路是什么:
// 首先,这种关于字符串匹配的问题一般都可以用dp来解, 用i来表示s1的前i个字符, j来表示s2的前j个字符
// 那么dp[i][j]就是表示 s1前i个和s2前j个的dp情况
// 这里dp就是 edit distance,即 s1前i个和s2前j个匹配时的edit distance solution
// dp[i][j] 只看s1的前i个和s2的前j个字符, 其他的都不管. 我们从后向前匹配, 如果s1[i-1]和s2[j-1]相同
// 就相当于可以把s1[i-1]和s2[j-1]各自从字符串里删除, 那么我们实际上就是比较s1[0:i-2]和s2[0:j-2], 即求dp[i-1][j-1].
// 同理,当 s1[i-1] != s2[j-1] 时, 我们有3种操作, 每个操做都会对 dp+1.
// 1. delete: 意味着s1[i-1]这个字符对于s1[0:i-1]匹配s2[0:j-1]而言时多余的,
//            把s1[i-1]从s1中删除后, s1[0:i-2]和s2[0:j-1]相互匹配, 这相当于做dp[i-1][j].
//            也就是说此时应该是dp[i][j] = dp[i-1][j] + 1
//
// 2. insert: 意味着把s1[i-1]前又塞了一个一个字符,这个字符是为了匹配s2[j-1], 那么我们可以把这两个字符同时删掉,
//            此时s1还是原样, s2少了s2[j-1], 并且此时满足匹配,相当于做了dp[i][j-1]
//            也就是说此时应该是dp[i][j] = dp[i][j-1] + 1
//
// 3. replace: 相当于s1换了s1[i-1]去匹配s2[j-1]. 之后s1[i-1]和s2[j-1]相等, 那么可以同时删除s1[i-1],s2[j-1].
//             也就是说此时应该是dp[i][j] = dp[i-1][j-1] + 1

int minDistance(string word1, string word2) {

    int m = word1.size();
    int n = word2.size();

    if(m == 0 || n == 0){
        return m == 0 ? n : m;
    }

    int dp[m + 1][n + 1] = {0};

    for(int i = 0; i < m + 1; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j < n + 1; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] += 1;
            }
        }
    }


    return dp[m][n];
}






//// dp solution without using "substr"
//int minDistance(string word1, string word2) {
//    return FindMinEditSteps(word1, word2, 0, 0);
//}
//
//// return the steps we need have to be edited from str1[s1_idx : end] and str2[s2_idx : end]
//int FindMinEditSteps(string& str1, string& str2, int s1_idx, int s2_idx){
//    string key = to_string(s1_idx) +" " + to_string(s2_idx);
//
//    if(resMap.count(key)){
//        return resMap[key];
//    }
//
//    if(s2_idx>=(int)str2.size()){
//        return resMap[key] = (str1.size()-s1_idx);
//    }
//
//    if(s1_idx>=(int)str1.size()){
//        return resMap[key] = (str2.size()-s2_idx);
//    }
//
//    if(str1[s1_idx] == str2[s2_idx]){
//        return resMap[key] = FindMinEditSteps(str1, str2, s1_idx+1, s2_idx+1);
//    }
//    else{
//        int ins_step = 1 + FindMinEditSteps(str1, str2, s1_idx, s2_idx+1);
//        int del_step = 1 + FindMinEditSteps(str1, str2, s1_idx+1, s2_idx);
//        int rep_step = 1 + FindMinEditSteps(str1, str2, s1_idx+1, s2_idx+1);
//        return resMap[key] = min(min(ins_step, del_step), rep_step);
//    }
//}

















//// 解法1 dp： 从后字符一个个向前剥
//int FindMinEditSteps(string str1, string str2){
//    int str_size_1 = str1.size();
//    int str_size_2 = str2.size();
//
//    //边界条件，如果一个字符串耗尽，那么剩下的步骤数就是另一个字符串的剩余长度
//    if(str_size_1==0){
//        return str_size_2;
//    }
//    if(str_size_2==0){
//        return str_size_1;
//    }
//
//    if(str1[str_size_1-1] == str2[str_size_2-1]){
//        // str2 last char equi
//        return FindMinEditSteps(str1.substr(0,str_size_1-1), str2.substr(0,str_size_2-1));
//    }
//
//    // str2 last char insert
//    int insert_dp = 1 + FindMinEditSteps(str1.substr(0,str_size_1-1), str2);
//    // str2 oth char delete
//    int delete_dp = 1 + FindMinEditSteps(str1, str2.substr(0,str_size_2-1));
//    // str2 oth char replace
//    int replace_dp = 1+ FindMinEditSteps(str1.substr(0,str_size_1-1), str2.substr(0,str_size_2-1));
//    return min(min(insert_dp, delete_dp), replace_dp);
//}



//
//// 解法2 dp: 从前字符一个个向后剥
//int FindMinEditSteps(string str1, string str2){
//    string key = str1+str2;
//    if(resMap.count(key)) return resMap[key];
//
//    if(str1.size()==0) return str2.size();
//    if(str2.size()==0) return str1.size();
//
//    int equStep = INT_MAX;
//    if(str1[0]==str2[0])
//        return equStep = FindMinEditSteps( str1.substr(1, str1.size()-1),  str2.substr(1, str2.size()-1) );
//
//    int delStep = 1 + FindMinEditSteps( str1,  str2.substr(1, str2.size()-1) );
//    int repStep = 1 + FindMinEditSteps( str1.substr(1, str1.size()-1),  str2.substr(1, str2.size()-1) );
//    int insStep = 1 + FindMinEditSteps( str1.substr(1, str1.size()-1),  str2 );
//
//    resMap[key] = min(delStep, min(repStep, insStep));
//    return resMap[key];
//}






