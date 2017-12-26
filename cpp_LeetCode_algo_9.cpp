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
