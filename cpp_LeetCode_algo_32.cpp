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

// �˷�����Ҫ˼��������string��index�� ����indexȥ��length
// ÿ������ƥ��ɹ���һ�ԾͰ�ƥ�䵽��indexɾ����ʣ�µ�ֻ��ûƥ�䵽��index
// ��ô������ƥ����־Ϳ���ֱ��ƥ������index�����������length
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
