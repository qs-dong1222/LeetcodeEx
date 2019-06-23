#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int myAtoi(string str);
bool is_sign(char ch);

int main(){

    string str =
    //"18446744073709551617";
    //"asdasf";
    //"     -121";
    //"      +-+-4512a234";
    "  -004512k234   ";
    cout << myAtoi(str) <<endl;;

    return 0;
}


/*
    solution 1
*/
//int myAtoi(string str) {
//    if(str.empty()) return 0;
//    // remove leading and tailing zeros
//    while(str[0]==' ') str.erase(0,1);
//    while(str[str.size()-1]==' ') str.erase(str.size()-1);
//
//    // remove tailing alphabets
//    for(int i=1;i<str.size();i++){
//        if(!isdigit(str[i])){
//            str.erase(str.begin()+i, str.end());
//            break;
//        }
//    }
//
//    // remove leading wrong char
//    if(str.size()>1 && !isdigit(str[1])) return 0;
//    if( !isdigit(str[0]) && str[0]!='+' && str[0]!='-') return 0;
//
//    int sign = str[0]=='-'? -1:1;
//
//    if(sign==-1 || str[0]=='+'){
//        str.erase(0,1);
//    }
//
//    long long ans = 0;
//    int n=str.size();
//    long long ten = 1;
//    for(int i=n-1;i>=0;i--){
//        ans += (str[i]-'0')*ten;
//        ten *= 10;
//        if(ans>INT_MAX){
//            if(sign==-1)
//                return INT_MIN;
//            else
//                return INT_MAX;
//        }
//    }
//
//    ans *= sign;
//    return ans;
//}




/*
    solution 2: 一个个字符扫, 考虑所有情况, 数值超界还是要重点考虑, 用大数范围去转换
*/
bool is_sign(char ch){
    return (ch=='+' || ch=='-');
}

int myAtoi(string s) {
    if(s.empty()) return 0;
    string ans = "";

    bool started = false;

    for(int i=0; i<(int)s.size(); i++){
        if(isdigit(s[i]) || is_sign(s[i])){
            if(!started){
                started = true;
                ans += s[i];
            }

            else if(started && isdigit(s[i])){
                ans += s[i];
            }

            else if(started && is_sign(s[i])){
                break;
            }
        }

        else if(s[i] == ' '){
            if(started){
                break;
            }
        }

        else if(s[i] != ' '){
            break;
        }

        if( !( ans.empty() || (ans.size()==1 && is_sign(ans[0])) ) ){
            long long int int_ans = stoll(ans);
            if(int_ans > INT_MAX){
                return INT_MAX;
            }
            else if(int_ans < INT_MIN){
                return INT_MIN;
            }
        }
    }

    if( ans.empty() || (ans.size()==1 && is_sign(ans[0])) ) return 0;
    else return stol(ans);

}

