#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
string Say(const string& s);
string countAndSay(int n);

int main(){

    string sayStr = countAndSay(10);
    cout << sayStr << endl;

//    string sayStr = Say("111221");
//    cout << sayStr << endl;
    return 0;
}


string countAndSay(int n) {
    if(n==0) return "";
    string sayStr = "1";
    for(int i=0; i<n-1 ; i++){
        sayStr = Say(sayStr);
    }
    return sayStr;
}


string Say(const string& s) {
    int cnt = 1;
    char ch = s[0];
    string ans;
    for(int i=1; i<(int)s.size(); i++){
        if(s[i] == ch)
            cnt++;
        else{
            ans.push_back(cnt+'0');
            ans.push_back(ch);
            cnt = 1;
            ch = s[i];
        }
    }
    ans.push_back(cnt+'0');
    ans.push_back(ch);
    return ans;
}
