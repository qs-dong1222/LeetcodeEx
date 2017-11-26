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
Leetcode�ϵ�����һ����ţB����
�˷��ĸ�Դ�����ڷָ
������ԭ�ַ��� great, ���Ƿֳ������֣���һ����gr, �ڶ�����eat
gr �� eat����������֧�� ����˵������һ��scramble���ַ��� rgate, ������ͬ����λ���Ϸָ�õ�
rg �� ate, ��Ȼrg�Ǵ�gr����scram�����ģ�ate�Ǵ�eat����scram�����ģ���ôһ������ֻҪȷ��������
����scramable�ľͿ����ˡ�����һ������� gr��eat���ˣ����eatgr���������������Ҫ��ԭ�ַ�����
ǰ���ʹ�ƥ���ַ����ĺ󲿽���ƥ�䡣
*/
bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size())
        return false;

    if(s1==s2)
        return true;

    // ���Ƿ����ַ�������ͬ��������ĸ����
    vector<int> chars(26,0);
    for(int i=0;i<s1.size();i++){
        chars[s1[i]-'a']++;
        chars[s2[i]-'a']--;
    }
    for(auto each : chars){
        if(each != 0)
            return false;
    }

    // �ڸ���λ���Ͻ��зָ�ָ�Ϊ�������ַ���������������ַ�������scramble����ô�������sramble��
    for(int i=1;i<s1.size();i++){
        if( isScramble(s1.substr(0,i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)) )
            return true;
        if( isScramble(s1.substr(0,i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i)) )
            return true;
    }
    return false;
}
