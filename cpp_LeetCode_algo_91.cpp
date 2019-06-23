#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s);

int main(){
    string s =
    //"2201";
    //"110";
    //"2213";
    "226";

    cout << numDecodings(s) << endl;

    return 0;
}


/*
    这个题有点艹淡, 花了点时间构建思路.
    dp的题字符串题, 应该是以各位置索引位基础建立各步骤dp结果.
    dp[i] : 以 ith 字符为结尾的给定字符串的 decode ways 个数
    以"2201"为例:
    第一个"2"只有一种解法, 到了第二个"2", 我们有两种解法---"2", "22"
    相当于这时候我们有两个分支,
    1. 第一个分支是把新来的"2"独立看待, 有x种decode ways解法(不是0的话, 其实只有一种,
       x=1, 因为'0'没得解, '1'代表'A'), 新来的"2"和之前的分支相互独立, 新来的"2"解自
       己这边的, 之前的字符串有自己解好的dp[i-1], 那么在新来的"2"有x种解法的基础上结
       合我们就有 dp[i-1] * x 种解法.
    2. 同理, 新来的"2"可以和前面的数结合, 那么结合两个数看成一个整体, 有y种decode解法.
       那么在此基础上, 我们有 dp[i-2] * y 种解法

    最终, 对于新来的"2", 我们有 dp[i-1] * x + dp[i-2] * y 种解法

    特殊情况是碰到新字符为"0". 此时, 新来的"0"单独看待无法成一个字. 那么x=0. 只能走第
    2th条分支.
*/
int numDecodings(string s) {
    if(s.empty()) return 0;

    vector<int> dp(s.size(), 0);

    for(int i=0;i<(int)s.size();i++){
        unsigned int dp_single_digit_path;
        unsigned int sigle_digit_decode_ways;
        if(s[i] == '0'){
            sigle_digit_decode_ways = 0;
        } else {
            sigle_digit_decode_ways = 1;
        }
        // 第一条分支的总decode ways 个数
        if(i-1>=0){
            dp_single_digit_path = dp[i-1] * sigle_digit_decode_ways;
        } else {
            dp_single_digit_path = sigle_digit_decode_ways;
        }

        unsigned int dp_double_digit_path;
        unsigned int double_digit_decode_ways;
        // '0'的特殊情况.
        // 两个数字不能是'00', '?0'也不能是超过26的数, 要不没得解
        if(i-1 >=0 && s[i-1] != '0' && stoi(s.substr(i-1, 2))+'A'-1<='Z'){
            double_digit_decode_ways = 1;
        } else {
            double_digit_decode_ways = 0;
        }
        // 第二条分支的总decode ways 个数
        if(i-2>=0){
            dp_double_digit_path = dp[i-2] * double_digit_decode_ways;
        } else {
            dp_double_digit_path = double_digit_decode_ways;
        }

        dp[i] = dp_single_digit_path + dp_double_digit_path;
    }

    return dp[s.size()-1];
}

















//int foo(string& str, bool& hasZero){
//    if(str.empty()){
//        hasZero = true;
//        return 0;
//    }
//    else if(str.size()==1){
//        hasZero = true;
//        if(str[0]=='0'){
//            return 0;
//        }
//        else return 1;
//    }
//    else if(str.size()>1){
//        if(str[0]=='0'){
//            hasZero = true;
//            return 0;
//        }
//        else{
//            hasZero = str[1]=='0'? true:false;
//        }
//    }
//
//    int count = 0;
//    if(str[0]=='1'){
//        count=1;
//    }
//    else if(str[0]=='2' && str[1]<='6'){
//        count=1;
//    }
//
//    for(int i=2;i<str.size();i++){
//        if(IsValid(str[i-1], str[i]))
//            count++;
//        if(str[i]=='0'){
//            hasZero=true;
//            if(!IsValid(str[i-1]))
//                return 0;
//            else if(i==2 && !IsValid(str[0])){
//                count++;
//            }
//        }
//    }
//
//    return count;
//}
//
//bool IsValid(const char& leftChar){
//    if(leftChar>='1'&& leftChar<='2')
//        return true;
//    return false;
//}
//
//bool IsValid(const char& leftChar, const char& rightChar){
//    if(IsValid(leftChar)){
//        if(leftChar=='1' && rightChar!='0'){
//            return true;
//        }
//        if(leftChar=='2' && rightChar>='1' && rightChar<='6'){
//            return true;
//        }
//    }
//    return false;
//}
