/*
�������ַ���,���ַ���2��Ϊ�ַ���1��������ٲ�����
��ѡ������
1) ɾһ���ַ�
2) ��һ���ַ�
3) ��һ���ַ�
*/

/*
�ⷨ��
�����Ӧ��˵�������ĵ�һ�����ֵ��ַ���DP����.
�ؼ������� : ��Ŀ��ļ�һ���ַ� �Ǳ�ʾ �ں����һ���ַ�, ��append
����DP˼·������Ҫ��������ٲ���������ô���ǵ�DP(x)��Ӧ�÷���һ�����ٲ�����.
���ձ�����˼�룬���������뵽����һ�����ַ�ȥ����DP.
�ؼ���subproblem����ô��˼·�����վ�������˼�룬����Ҫ����ÿ���ַ��м��ֲ�����
�����Ҫ�����ø����ӣ���һ��.
str1 = abcdef
str2 = bcde
������ǵĴӾ�������߲㿪ʼ�����������ַ������룬����Ӧ��ȥ��DP(n-1)�����.
DP(n-1) �� DP(n) ��Ҫʲô���м��ֿ�����(�м���������֧)��
1) str2[e]������һ���ַ�ȥƥ��str1, ��ô�ͱ��bcdef, ���һ���ַ�f���˲�����ɣ����Բ�ȥ���ǣ�
   ���ǽ���ֻ���� str1 = abcde �� str2 = bcde
   ����˵һ��str2������2)�����ǵ���һ������ str2(:) �� str1(0:n-2)
2) ͬ������Ƴ�����������1)ʱ�����ǵ���һ��Ӧ���� str2(0:n-2) �� str1(:)
3) �����ַ���һ���ַ����滻����ô��һ���ַ��������һλ�ͻ����ƥ�䣬��ô���ǵ���һ������
   str2(0:n-2) �� str1(0:n-2)
���������ֲ���������һ�����裬��ô��DP(x)�ж���+1.

����һ������ǣ������ַ���ȣ���ô����ͬʱ��ȥ����������DP(x)+1�Ĳ���.

���� DP( str1(0:n), str2(0:n) ) = min(1+DP(��)/DP(ɾ)/DP(��)) or DP( str1(0:n-1), str2(0:n-1) )
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
// ����һ��˼·��ʲô:
// ����,���ֹ����ַ���ƥ�������һ�㶼������dp����, ��i����ʾs1��ǰi���ַ�, j����ʾs2��ǰj���ַ�
// ��ôdp[i][j]���Ǳ�ʾ s1ǰi����s2ǰj����dp���
// ����dp���� edit distance,�� s1ǰi����s2ǰj��ƥ��ʱ��edit distance solution
// dp[i][j] ֻ��s1��ǰi����s2��ǰj���ַ�, �����Ķ�����. ���ǴӺ���ǰƥ��, ���s1[i-1]��s2[j-1]��ͬ
// ���൱�ڿ��԰�s1[i-1]��s2[j-1]���Դ��ַ�����ɾ��, ��ô����ʵ���Ͼ��ǱȽ�s1[0:i-2]��s2[0:j-2], ����dp[i-1][j-1].
// ͬ��,�� s1[i-1] != s2[j-1] ʱ, ������3�ֲ���, ÿ����������� dp+1.
// 1. delete: ��ζ��s1[i-1]����ַ�����s1[0:i-1]ƥ��s2[0:j-1]����ʱ�����,
//            ��s1[i-1]��s1��ɾ����, s1[0:i-2]��s2[0:j-1]�໥ƥ��, ���൱����dp[i-1][j].
//            Ҳ����˵��ʱӦ����dp[i][j] = dp[i-1][j] + 1
//
// 2. insert: ��ζ�Ű�s1[i-1]ǰ������һ��һ���ַ�,����ַ���Ϊ��ƥ��s2[j-1], ��ô���ǿ��԰��������ַ�ͬʱɾ��,
//            ��ʱs1����ԭ��, s2����s2[j-1], ���Ҵ�ʱ����ƥ��,�൱������dp[i][j-1]
//            Ҳ����˵��ʱӦ����dp[i][j] = dp[i][j-1] + 1
//
// 3. replace: �൱��s1����s1[i-1]ȥƥ��s2[j-1]. ֮��s1[i-1]��s2[j-1]���, ��ô����ͬʱɾ��s1[i-1],s2[j-1].
//             Ҳ����˵��ʱӦ����dp[i][j] = dp[i-1][j-1] + 1

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

















//// �ⷨ1 dp�� �Ӻ��ַ�һ������ǰ��
//int FindMinEditSteps(string str1, string str2){
//    int str_size_1 = str1.size();
//    int str_size_2 = str2.size();
//
//    //�߽����������һ���ַ����ľ�����ôʣ�µĲ�����������һ���ַ�����ʣ�೤��
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
//// �ⷨ2 dp: ��ǰ�ַ�һ��������
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






