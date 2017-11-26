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

using namespace std;


int FindMinEditSteps(string str1, string str2);

unordered_map<string, int> res;

int main(){
    string str1 = "abcdef";
    string str2 = "cvf";

    cout <<FindMinEditSteps(str1, str2) <<endl;

    return 0;
}


// �ⷨ1�� �Ӻ��ַ�һ������ǰ��
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




// �ⷨ2 ��ǰ�ַ�һ��������
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






