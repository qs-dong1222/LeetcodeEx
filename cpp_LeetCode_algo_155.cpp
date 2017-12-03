#include <iostream>
#include <vector>
#include <stack>

using namespace std;




class MinStack {
public:
    MinStack() {
        __minVal = INT_MAX;
    }

    void push(int x) {
        if(x <= __minVal){
            __mystk.push(__minVal); // record the old __minVal into stack when update the __minVal
            __minVal = x;
        }
        __mystk.push(x); // push real value that needed to be push in
    }

    void pop() {
        if(__mystk.top() == __minVal){
            // this top value equals to __minVal, so it comes with the update of __minVal,
            // follows with a old __minVal in stack
            __mystk.pop();
            if(!__mystk.empty()){
                __minVal = __mystk.top();
                __mystk.pop();
            }
        }
        else{
            if(!__mystk.empty()){
                __mystk.pop();
            }
        }
    }

    int top() {
        return __mystk.top();
    }

    int getMin() {
        if(__mystk.empty()){
            return 0;
        }
        else{
            return __minVal;
        }
    }

private:
    stack<int> __mystk;
    int __minVal;
};








int main(){

    return 0;
}




