#include <iostream>
#include <vector>

using namespace std;
bool IsPalindrome(string& s, int lidx, int ridx);

int main(){
    string s = "cbbd";

    int lidx, ridx;
    for(int len=s.size(); len>0; len--){
        for(lidx=0, ridx=lidx+len-1; ridx<s.size(); lidx++,ridx++) {
            if(IsPalindrome(s, lidx, ridx)){
                cout << "final len = "<< len << endl;
                cout << "Palindrome string = "<< s.substr(lidx,len) << endl;
                return 0;
            }
        }
    }

    cout << "no Palindrome, len = 1" << endl;

    return 0;
}

bool IsPalindrome(string& s, int lidx, int ridx){
    while(lidx < ridx){
        if(s[lidx++]!=s[ridx--]) return false;
    }
    return true;
}
