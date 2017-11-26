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

using namespace std;


int FindMinEditSteps(string str1, string str2);

unordered_map<string, int> res;

int main(){
    string str1 = "abcdef";
    string str2 = "cvf";

    cout <<FindMinEditSteps(str1, str2) <<endl;

    return 0;
}


// 解法1： 从后字符一个个向前剥
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




// 解法2 从前字符一个个向后剥
int FindMinEditSteps(string str1, string str2){
    string key = str1+str2;
    if(resMap.count(key)) return resMap[key];

    if(str1.size()==0) return str2.size();
    if(str2.size()==0) return str1.size();

    int equStep = INT_MAX;
    if(str1[0]==str2[0])
        return equStep = FindMinEditSteps( str1.substr(1, str1.size()-1),  str2.substr(1, str2.size()-1) );

    int delStep = 1 + FindMinEditSteps( str1,  str2.substr(1, str2.size()-1) );
    int repStep = 1 + FindMinEditSteps( str1.substr(1, str1.size()-1),  str2.substr(1, str2.size()-1) );
    int insStep = 1 + FindMinEditSteps( str1.substr(1, str1.size()-1),  str2 );

    resMap[key] = min(delStep, min(repStep, insStep));
    return resMap[key];
}






