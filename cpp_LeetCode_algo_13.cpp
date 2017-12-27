#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int romanToInt(string s);

int main(){

    cout << romanToInt("MDCCLXXXIX") <<endl;

    return 0;
}


int romanToInt(string s) {
    int ans = 0;
    if(s.empty()) return ans;

    unordered_map<char, int> roman;
    roman['M'] = 1000;
    roman['D'] = 500;
    roman['C'] = 100;
    roman['L'] = 50;
    roman['X'] = 10;
    roman['V'] = 5;
    roman['I'] = 1;

    int maxInt = roman[s[s.size()-1]];
    for(int i=s.size()-1;i>=0;i--){
        if(roman[s[i]] < maxInt){
            ans -= roman[s[i]];
        }
        else{
            ans += roman[s[i]];
            maxInt = max(maxInt, roman[s[i]]);
        }
    }
    return ans;
}
