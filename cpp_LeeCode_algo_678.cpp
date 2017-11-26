#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <stdlib.h>
#include <string.h>

using namespace std;

//bool IsParenthesisMatch(char* str);
bool IsParenthesisMatch(char* str, int left_idx, int right_idx);

int main(){

    char* aaa = "())(";

    cout << IsParenthesisMatch(aaa, 0, strlen(aaa)-1) <<endl;

    return 0;
}

// Solution 1
//bool IsParenthesisMatch(char* str){
//    int n_leftp = 0;
//    int strLen = strlen(str);
//
//    int i;
//    for(i=0;i<strLen;i++){
//        if(str[i] == '('){
//            n_leftp++;
//        }
//        else if(str[i] == ')' && n_leftp>0){
//            n_leftp--;
//        }
//        else if(str[i] == '*' && n_leftp>0){
//            n_leftp--;
//        }
//        else{
//            ;
//        }
//    }
//
//    return n_leftp<=0 ? true : false;
//}





// Solution 2 Dynamic programming
bool IsParenthesisMatch(char* str, int left_idx, int right_idx){
    int len = right_idx - left_idx + 1;

    // no char in str
    if(len == 0){
        return true;
    }
    // 1 char in str
    else if(len == 1){
        if(str[0] != '('){
            return true;
        }
        else{
            return false;
        }
    }
    // 2 chars in str
    else if(len == 2){
        int n_leftp = 0, i;
        for(i=0;i<2;i++){
            if( str[left_idx+i] == '('){
                n_leftp++;
            }
            else if( n_leftp>0 && (str[left_idx+i] == '*' || str[left_idx+i] == ')') ){
                n_leftp--;
            }
        }
        return n_leftp>0? false:true;
    }
    // more than 2 chars in str
    else{
        return ( IsParenthesisMatch(str, left_idx, right_idx/2)
                 && IsParenthesisMatch(str, right_idx/2+1, right_idx) );
    }
}

