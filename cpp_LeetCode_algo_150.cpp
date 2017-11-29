#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
int evalRPN(vector<string>& tokens);

int main(){

    vector<string> sss = {"4", "13", "5", "/", "+"};
    cout << evalRPN(sss) << endl;

    return 0;
}


int evalRPN(vector<string>& tokens) {
    if(tokens.empty()) return 0;

    stack<int> stk;

    for(int i=0;i<tokens.size();i++){
        if(tokens[i] == "+"){
            if(!stk.empty()){
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first+second);
            }
        }
        else if(tokens[i] == "-"){
            if(!stk.empty()){
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first-second);
            }
        }
        else if(tokens[i] == "*"){
            if(!stk.empty()){
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first*second);
            }
        }
        else if(tokens[i] == "/"){
            if(!stk.empty()){
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first/second);
            }
        }
        else{
            stk.push(stoi(tokens[i]));
        }
    }

    return stk.top();
}
