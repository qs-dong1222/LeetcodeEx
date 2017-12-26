#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int myAtoi(string str);


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



int myAtoi(string str) {
    if(str.empty()) return 0;
    // remove leading and tailing zeros
    while(str[0]==' ') str.erase(0,1);
    while(str[str.size()-1]==' ') str.erase(str.size()-1);

    // remove tailing alphabets
    for(int i=1;i<str.size();i++){
        if(!isdigit(str[i])){
            str.erase(str.begin()+i, str.end());
            break;
        }
    }

    // remove leading wrong char
    if(str.size()>1 && !isdigit(str[1])) return 0;
    if( !isdigit(str[0]) && str[0]!='+' && str[0]!='-') return 0;

    int sign = str[0]=='-'? -1:1;

    if(sign==-1 || str[0]=='+'){
        str.erase(0,1);
    }

    long long ans = 0;
    int n=str.size();
    long long ten = 1;
    for(int i=n-1;i>=0;i--){
        ans += (str[i]-'0')*ten;
        ten *= 10;
        if(ans>INT_MAX){
            if(sign==-1)
                return INT_MIN;
            else
                return INT_MAX;
        }
    }

    ans *= sign;
    return ans;
}
