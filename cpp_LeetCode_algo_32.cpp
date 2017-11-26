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

// 此方法主要思想是利用string的index， 利用index去求length
// 每次碰到匹配成功的一对就把匹配到的index删除，剩下的只是没匹配到的index
// 那么再有新匹配出现就可以直接匹配更早的index，求出更长的length
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
