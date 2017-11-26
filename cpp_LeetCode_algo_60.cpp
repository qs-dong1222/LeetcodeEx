#include <iostream>
#include <vector>
#include <set>

using namespace std;

//void per(string& str, int begin, set<string>& ans);
//string generateStr(int n);
string getPermutation(int n, int k);
vector<int> fac(int n);

int main(){

    cout << getPermutation(4, 12) << endl;

    return 0;
}



/*
ţ���㷨:
����㷨��˼·�����ȥ�ҹ��ɣ���һ���������ҹ���.
���ӣ�n=4 --> "1234" , ȫ����Ϊ
1234    1st
1243    2nd
1324    3rd
1342    4th
1423    5th
1432    6th
-----------
2134    7th
2143    8th
2314    9th
2341    10th
2413    11th
2431    12th
------------
3124    13th
3142    14th
3214    15th
3241    16th
3412    17th
3421    18th
...     ...

���ǿ��Թ۲쵽ȫ�������Ը����ַ� ��1�� ��2�� ��3�� ��4�� �ֱ�Ϊ��ʼ�ַ���ÿ����ʼ�ַ���6������Ϊһ�飬
���� 3! ��ȫ����Ϊһ�� = �� (string.size-initChar.size)! = (string.size-1)! ��ȫ����Ϊһ��.
����˵������15th����˵�������Ѿ�������ǰ������(1st~12th), ��������3!*(15/3!)��ȫ����. ���ʱ��
��ȫ����Ӧ����'3'��ͷ��Ҳ����(��1�� ��2�� ��3�� ��4��)�еĵ�3��, ����(15/3!)+1������ʱ����ȷ���˵�һ���ַ�.
ͬ�����ǿ����ҵ��ڶ����ַ�����ʱʣ��������ַ�Ϊ ��1�� ��2�� ��4��, ���ڡ�3����ͷ��ȫ����������, ��ô
��Ӧ��������(15-12)th = (15-3!*(15/3!))th = 3thȫ����. ��ʱ��ȥѰ�Ҵ�ͷ�ַ���ÿ����ͷ�ַ�Ӧ����
2! ��ȫ���С���ô���������� 2!*(3/2!)=2 ��ȫ����, ����ͷ�ַ�Ϊ��(3/2!)+1=2��, ����2��. ��ʱ�ѵõ�"32".
�����Դ����Ƽ��ɡ�

���˼·��ʵ�ܲ����룬��������Ҫ�г����п��ܣ�Ѱ�ҹ��ɣ����һ������û�Һã��͵ò������ۡ�
*/

string getPermutation(int n, int k) {
    if(n==0 || k==0) return "";
    string leftOverInitChar = "123456789";
    vector<int> factorial = fac(n);
    string ans;

    int currFac;
    k--;
    while(n>=1){
        currFac = factorial[n-1];
        ans.push_back( leftOverInitChar[k/currFac] );
        leftOverInitChar.erase(k/currFac, 1);
        k = k%currFac;
        n--;
    }
    return ans;
}


vector<int> fac(int n){
    if(n==0) return vector<int>(1,1);

    vector<int> ans;
    ans.push_back(1); // 0!
    int a=1;
    for(int i=1;i<=n;i++){
        a *= i;
        ans.push_back(a);
    }
    return ans;
}














/*
��ʱ�㷨��ȫö�����У�������������
̫�����ù�
*/
//string getPermutation(int n, int k) {
//    string str = generateStr(n);
//    set<string> ans;
//    per(str, 0, ans);
//    set<string>::iterator it=ans.begin();
//    for(int i=0; i<k-1; i++) advance(it,1);
//    return *it;
//}
//string generateStr(int n){
//    string ans;
//    for(int i=1;i<=n;i++){
//        ans.push_back(i+'0');
//    }
//    return ans;
//}
//void per(string& str, int begin, set<string>& ans){
//    if(begin >= str.size()){
//        ans.insert(str);
//        return;
//    }
//
//    for(int i=begin; i<str.size(); i++){
//        swap(str[begin], str[i]);
//        per(str, begin+1, ans);
//        swap(str[begin], str[i]);
//    }
//}
