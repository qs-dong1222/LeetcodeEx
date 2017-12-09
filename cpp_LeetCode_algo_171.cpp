#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int titleToNumber(string s);

int main(){

    cout << titleToNumber("AZZ") << endl;


    return 0;
}


int titleToNumber(string s) {
    double ans = 0;
    if(s.empty()) return ans;

    int exp = 0;
    while(!s.empty()){
        char lastChar = s[s.size()-1];
        ans +=  (lastChar-'A'+1) * pow(26, exp);
        s.pop_back();
        exp++;
    }
    return ans;
}
