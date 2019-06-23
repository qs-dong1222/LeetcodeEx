#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
bool isPalindrome(int x);

int main(){

    int x = 12321;
    cout << isPalindrome(x) << endl;

    return 0;
}

bool isPalindrome(int x) {
    if(x<0) return false;
    int y = x;
    int ans = 0;
    while(y>0){
        ans = ans*10 + y%10;
        y /= 10;
    }

    return (ans==x);
}



bool isPalindrome(int x) {
    if(x < 0) return false;

    stringstream ss;
    ss<<x;
    string s = ss.str();
    reverse(s.begin(), s.end());
    ss.str("");
    ss << s;
    long int int_ans = 0;
    ss>>int_ans;
    if(int_ans > INT_MAX || int_ans < INT_MIN) return false;
    return (int_ans == x);
}

