#include <iostream>
#include <vector>
#include <string>

using namespace std;
string Say(const string& s);
string countAndSay(int n);

int main(){

    string sayStr = countAndSay(5);
    cout << sayStr << endl;

    //string sayStr = Say("21");
    //cout << sayStr << endl;
    return 0;
}



string countAndSay(int n) {
    string ans = "1";
    if(n<=1) return ans;

    return Say( countAndSay(n-1) );
}


string Say(const string& s){
    string ans;
    if(s.empty()) return ans;

    int count = 1;
    char curCh = s[0];
    int i=1;
    while(i<(int)s.size()){
        if(s[i]==curCh){
            count++;
        }
        else{
            ans += to_string(count);
            ans.push_back(curCh);
            count = 1;
            curCh = s[i];
        }
        i++;
    }
    ans += to_string(count);
    ans.push_back(curCh);

    return ans;
}

