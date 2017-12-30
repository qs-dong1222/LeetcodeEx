#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Elem{
    char ch;
    int parCnt;
};

int longestValidParentheses(string s);

int main(){
    string s= ")(())))(())())";

    cout <<longestValidParentheses(s) << endl;

    return 0;
}






/*
�������ʵһ��ʼ�뵽������stackȥ��'('��index, ����')'��ȥ��stk.top(), �ڸ�����Ծ���.
�������ַ�������"()()"��û�а취����Ϊ����ÿ�θ��µ��Ǵ�����������'('����������')'�ľ���.
�ظ����ֵ�"()()"���ֻ�ܼ�¼��2.

���룬���һ�����ǵ�ǰ���� ��Ч���Ŵ� �У���ô˵����֮ǰĳ����һλ�ÿ�ʼ������ǰλ�ö�����Ч�ģ�����ֻ��
�����ǰλ�����Ǹ���һλ�õ���Ծ��뼴��.
����:
 ) ( ( ) ) ( ) )
 0 1 2 3 4 5 6 7
 ��һ����Чλ����1, �� 3 4 6ʱ���Ƕ��������1�ľ�����㣬��ô����ͳ�Ƴ���ȷ�Ľ��.
 ����1���index��������4���')'ʱ������, ������Ҫһ����ʱ���ᱻ�����Ĳο�λ��. ǡǡ0����')'
 ������Ϊ�ο�λ��. ���������� ��Ч���Ŵ� ͳ��ʱ, Ӧ�ü�¼�ʼ���Ǹ���Ч�ַ���λ��.
 ��ô��������, "()()" ����û���ʼ����Ч�ַ���ô�죿 �Լ���һ����Ч�ַ��Ĳο�λ�þͿ�����.
 ��Ҳ����Ϊʲô���ǻ���stk.push(-1)
*/
int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int len = 0;

    for(int i=0;i<s.size();i++){
        if(s[i]==')' && s[stk.top()]=='('){
            stk.pop();
            len = max(i-stk.top(), len);
        }
        else{
            stk.push(i);
        }
    }
    return len;
}




