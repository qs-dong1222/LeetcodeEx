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
这道题其实一开始想到的是用stack去存'('的index, 碰见')'就去消stk.top(), 在更新相对距离.
但是这种方法对于"()()"就没有办法，因为我们每次更新的是从最晚碰到的'('到最新碰到')'的距离.
重复出现的"()()"最多只能记录到2.

又想，如果一个我们当前处于 有效括号串 中，那么说明从之前某个第一位置开始，到当前位置都是有效的，我们只需
求出当前位置与那个第一位置的相对距离即可.
例子:
 ) ( ( ) ) ( ) )
 0 1 2 3 4 5 6 7
 第一个有效位置是1, 在 3 4 6时我们都作相对于1的距离计算，那么就能统计出正确的结果.
 但是1这个index会在碰到4这个')'时被消掉, 我们需要一个此时不会被消掉的参考位置. 恰恰0处的')'
 可以作为参考位置. 所以我们作 有效括号串 统计时, 应该记录最开始的那个无效字符的位置.
 那么问题来了, "()()" 这种没有最开始的无效字符怎么办？ 自己添一个无效字符的参考位置就可以了.
 这也就是为什么我们会有stk.push(-1)
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




