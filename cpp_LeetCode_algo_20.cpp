#include <stack>
#include <iostream>

using namespace std;
bool isValid(string s);

int main(){
    string s = "(({[)]}))";
    cout << isValid(s) << endl;

    return 0;
}


bool isValid(string s) {
    stack<char> stk;
    for(auto ch : s){
        if(ch=='(' || ch=='[' || ch=='{'){
            stk.push(ch);
        }
        else if(!stk.empty()){
            if(ch == ')' && stk.top()=='(')
                stk.pop();
            else if(ch == ']' && stk.top()=='[')
                stk.pop();
            else if(ch == '}' && stk.top()=='{')
                stk.pop();
            else return false;
        }
        else{
            return false;
        }
    }
    return stk.empty();
}
