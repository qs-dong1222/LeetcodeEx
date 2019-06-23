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
    ������е�ܳ��, ���˵�ʱ�乹��˼·.
    dp�����ַ�����, Ӧ�����Ը�λ������λ��������������dp���.
    dp[i] : �� ith �ַ�Ϊ��β�ĸ����ַ����� decode ways ����
    ��"2201"Ϊ��:
    ��һ��"2"ֻ��һ�ֽⷨ, ���˵ڶ���"2", ���������ֽⷨ---"2", "22"
    �൱����ʱ��������������֧,
    1. ��һ����֧�ǰ�������"2"��������, ��x��decode ways�ⷨ(����0�Ļ�, ��ʵֻ��һ��,
       x=1, ��Ϊ'0'û�ý�, '1'����'A'), ������"2"��֮ǰ�ķ�֧�໥����, ������"2"����
       ����ߵ�, ֮ǰ���ַ������Լ���õ�dp[i-1], ��ô��������"2"��x�ֽⷨ�Ļ����Ͻ�
       �����Ǿ��� dp[i-1] * x �ֽⷨ.
    2. ͬ��, ������"2"���Ժ�ǰ��������, ��ô�������������һ������, ��y��decode�ⷨ.
       ��ô�ڴ˻�����, ������ dp[i-2] * y �ֽⷨ

    ����, ����������"2", ������ dp[i-1] * x + dp[i-2] * y �ֽⷨ

    ����������������ַ�Ϊ"0". ��ʱ, ������"0"���������޷���һ����. ��ôx=0. ֻ���ߵ�
    2th����֧.
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
        // ��һ����֧����decode ways ����
        if(i-1>=0){
            dp_single_digit_path = dp[i-1] * sigle_digit_decode_ways;
        } else {
            dp_single_digit_path = sigle_digit_decode_ways;
        }

        unsigned int dp_double_digit_path;
        unsigned int double_digit_decode_ways;
        // '0'���������.
        // �������ֲ�����'00', '?0'Ҳ�����ǳ���26����, Ҫ��û�ý�
        if(i-1 >=0 && s[i-1] != '0' && stoi(s.substr(i-1, 2))+'A'-1<='Z'){
            double_digit_decode_ways = 1;
        } else {
            double_digit_decode_ways = 0;
        }
        // �ڶ�����֧����decode ways ����
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
