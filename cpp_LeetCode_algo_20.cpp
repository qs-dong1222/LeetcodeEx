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
    if(s.empty()) return true;

    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stk.push(s[i]);
        }
        else if(s[i]==')' && !stk.empty() && stk.top()=='('){
            stk.pop();
        }
        else if(s[i]=='}' && !stk.empty() && stk.top()=='{'){
            stk.pop();
        }
        else if(s[i]==']' && !stk.empty() && stk.top()=='['){
            stk.pop();
        }
        else{
            return false;
        }
    }

    return stk.empty();
}











//bool isValid(string s) {
//    stack<char> stk;
//    for(auto ch : s){
//        if(ch=='(' || ch=='[' || ch=='{'){
//            stk.push(ch);
//        }
//        else if(!stk.empty()){
//            if(ch == ')' && stk.top()=='(')
//                stk.pop();
//            else if(ch == ']' && stk.top()=='[')
//                stk.pop();
//            else if(ch == '}' && stk.top()=='{')
//                stk.pop();
//            else return false;
//        }
//        else{
//            return false;
//        }
//    }
//    return stk.empty();
//}
